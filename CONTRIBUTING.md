# Contributing to CICERONE AirLink

Thank you for your interest in contributing to CICERONE AirLink! This document provides guidelines and instructions for contributing to this project.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [How to Contribute](#how-to-contribute)
- [Development Workflow](#development-workflow)
- [Coding Standards](#coding-standards)
- [Testing Guidelines](#testing-guidelines)
- [Documentation](#documentation)
- [Commit Messages](#commit-messages)
- [Pull Request Process](#pull-request-process)
- [Reporting Issues](#reporting-issues)
- [Questions](#questions)

## Code of Conduct

This project and everyone participating in it is governed by our Code of Conduct. By participating, you are expected to uphold this code. Please report unacceptable behavior to the project maintainers through GitHub.

### Our Standards

**Positive behaviors include:**

- Using welcoming and inclusive language
- Being respectful of differing viewpoints and experiences
- Gracefully accepting constructive criticism
- Focusing on what is best for the community
- Showing empathy towards other community members

**Unacceptable behaviors include:**

- Harassment, trolling, or derogatory comments
- Public or private harassment
- Publishing others' private information without permission
- Other conduct which could reasonably be considered inappropriate

## Getting Started

### Prerequisites

Before contributing, ensure you have:

- **Git** installed and configured
- **Arduino CLI** (for firmware development)
- **Python 3.8+** with pip (for documentation)
- **MkDocs Material** (for documentation preview)
- Basic knowledge of the project architecture (see [documentation](https://atari-researchlab.github.io/cicerone-airlink))

### Setting Up Your Development Environment

1. **Fork the repository** on GitHub

2. **Clone your fork** locally:

   ```bash
   git clone https://github.com/YOUR-USERNAME/cicerone-airlink.git
   cd cicerone-airlink
   ```

3. **Add upstream remote**:

   ```bash
   git remote add upstream https://github.com/atari-researchlab/cicerone-airlink.git
   ```

4. **Install Arduino dependencies** (for firmware development):

   ```bash
   arduino-cli core install arduino:mbed_nano
   arduino-cli lib install "ArduinoJson" "Sensirion I2C SEN5X" "Sensirion Core"
   ```

5. **Install documentation tools**:

   ```bash
   pip install mkdocs-material mkdoxy
   ```

6. **Create a development branch**:

   ```bash
   git checkout -b feature/your-feature-name
   ```

## How to Contribute

We welcome various types of contributions:

### 🐛 Bug Reports

Found a bug? Please help us by:

1. Checking if the issue already exists in [GitHub Issues](https://github.com/atari-researchlab/cicerone-airlink/issues)
2. Creating a detailed bug report with:
   - Clear title and description
   - Steps to reproduce
   - Expected vs actual behavior
   - Hardware/software versions
   - Debug logs (if applicable)
   - Screenshots (if relevant)

### 💡 Feature Requests

Have an idea? We'd love to hear it:

1. Check existing issues to avoid duplicates
2. Describe the feature and its benefits
3. Explain use cases
4. Provide examples or mockups if possible

### 📝 Documentation Improvements

Documentation can always be better:

- Fix typos or clarify unclear sections
- Add examples or tutorials
- Translate documentation (especially to Spanish)
- Improve API documentation

### 🔧 Code Contributions

Ready to code? Great! See [Development Workflow](#development-workflow) below.

## Development Workflow

### 1. Sync with Upstream

Before starting work, sync your fork:

```bash
git checkout main
git fetch upstream
git merge upstream/main
git push origin main
```

### 2. Create a Feature Branch

```bash
git checkout -b feature/descriptive-name
# or
git checkout -b fix/bug-description
# or
git checkout -b docs/documentation-update
```

**Branch naming conventions:**

- `feature/` - New features
- `fix/` - Bug fixes
- `docs/` - Documentation only
- `refactor/` - Code refactoring
- `test/` - Adding or updating tests
- `hardware/` - Hardware design changes

### 3. Make Your Changes

Follow our [Coding Standards](#coding-standards) and keep commits focused and atomic.

### 4. Test Your Changes

- **Firmware**: Compile and test on actual hardware when possible
- **Documentation**: Preview locally with `mkdocs serve`
- **Hardware**: Validate designs with DRC and ERC checks

### 5. Commit Your Changes

Follow our [Commit Message Guidelines](#commit-messages):

```bash
git add .
git commit -m "feat: add support for new sensor"
```

### 6. Push to Your Fork

```bash
git push origin feature/descriptive-name
```

### 7. Open a Pull Request

Go to GitHub and create a Pull Request from your fork to `atari-researchlab/cicerone-airlink:main`.

## Coding Standards

### Firmware (C/C++)

#### General Guidelines

- Follow **existing code style** and conventions
- Use **meaningful variable names** (no single-letter names except loop counters)
- Keep functions **small and focused** (single responsibility principle)
- **Comment complex logic** and non-obvious decisions
- Use **Doxygen-style comments** for all functions and files

#### File Organization

```cpp
/**
 * @file    ModuleName.h
 * @brief   Brief description of the module
 * @details Detailed description if needed
 * @author  [Your Name]
 * @date    [YYYY-MM-DD]
 * @version X.Y
 * @copyright GNU General Public License version 3 or later
 */

#ifndef MODULE_NAME_H
#define MODULE_NAME_H

// Includes
#include <Arduino.h>
#include "OtherHeaders.h"

// Constants
#define CONSTANT_NAME value

// Function prototypes
void function_name(void);

#endif // MODULE_NAME_H
```

#### Naming Conventions

- **Files**: `PascalCase.h`, `PascalCase.cpp`, `snake_case.ino`
- **Functions**: `snake_case()` (e.g., `sen5x_leer()`)
- **Variables**: `snake_case` (e.g., `avg_sen5x_mc_2p5`)
- **Constants**: `UPPER_SNAKE_CASE` (e.g., `DEBUG_LEVEL`)
- **Macros**: `UPPER_SNAKE_CASE` (e.g., `HABILITAR_NBIOT`)

#### Code Style

```cpp
// Good: Clear, documented, follows conventions
/**
 * @brief Reads CO2 sensor and returns concentration
 * @return true if reading successful, false otherwise
 */
bool t6793_leer(void) {
  if (!sensor.available()) {
    DEBUG_ERROR("Sensor not available");
    return false;
  }

  t6793_co2 = sensor.readCO2();
  DEBUG_VERBOSE("CO2: %.2f ppm", t6793_co2);

  return true;
}

// Bad: Unclear, uncommented, poor naming
bool rd(void) {
  if (!s.av()) return false;
  c = s.r();
  return true;
}
```

#### Memory Management

- Prefer **static allocation** over dynamic
- Use **F() macro** for string literals in Serial.print()
- Avoid **memory leaks** - free what you allocate
- Minimize **global variables** - use extern declarations

#### Hardware Interaction

- Use **non-blocking code** (avoid `delay()` except in setup)
- Implement proper **error handling** for I2C/UART
- Check **return values** from sensor functions
- Use **appropriate pull-up/pull-down** configurations

### Documentation (Markdown)

- Follow **Markdown linting rules** (see `.markdownlint.yml`)
- Use **proper heading hierarchy** (H1 → H2 → H3)
- Include **code examples** with language specifiers
- Add **blank lines** around code blocks and lists
- Use **admonitions** for notes, warnings, tips (Material for MkDocs)

Example:

```markdown
## Section Title

Regular paragraph text.

!!! note "Important Information"
    This is a note admonition with proper indentation.

### Subsection

- List item 1
- List item 2

Code example:

~~~cpp
void example_function(void) {
    // Code here
}
~~~

```

### Hardware (PCB Design)

- Follow **IPC standards** for PCB design
- Use **clear silkscreen labels** for components
- Implement proper **ground planes** and **power distribution**
- Include **design rule checks** (DRC) in pull request
- Document **BOM changes** in commit message
- Provide **gerber files** for significant changes

## Testing Guidelines

### Firmware Testing

Before submitting firmware changes:

1. **Compile without errors**:

   ```bash
   arduino-cli compile --profile nano33ble firmware/
   ```

1. **Test on hardware** (if possible):
   - Upload to actual Arduino Nano 33 BLE Sense Rev2
   - Verify all sensors respond correctly
   - Check debug output via serial monitor
   - Validate data transmission (if NB-IoT enabled)

1. **Check memory usage**:
   - Ensure flash usage < 80% of available
   - Ensure RAM usage < 75% of available

1. **Test edge cases**:
   - Sensor disconnection/reconnection
   - Network failures
   - Power interruptions (if applicable)

### Documentation Testing

1. **Build documentation locally**:

   ```bash
   mkdocs build --strict
   ```

2. **Preview changes**:

   ```bash
   mkdocs serve
   ```

3. **Check for broken links** and formatting issues

4. **Validate code examples** actually work

### Hardware Testing

1. **Run DRC** (Design Rule Check) in your PCB software
2. **Run ERC** (Electrical Rule Check) for schematics
3. **Verify footprints** match actual components
4. **Check power requirements** and current ratings
5. **Review thermal considerations**

## Documentation

### API Documentation (Doxygen)

All functions, variables, and files should have Doxygen comments:

```cpp
/**
 * @brief Brief description (one line)
 * @details More detailed explanation of what the function does,
 * how it works, and any important considerations.
 *
 * @param[in] param_name Description of input parameter
 * @param[out] result Description of output parameter
 * @return Description of return value
 *
 * @note Important notes or warnings
 * @warning Critical warnings
 * @see Related functions or documentation
 *
 * @code
 * // Usage example
 * int result = example_function(42);
 * @endcode
 */
int example_function(int param_name);
```

### User Documentation (MkDocs)

When adding user-facing documentation:

- Place in appropriate directory under `docs/`
- Update `mkdocs.yml` navigation if adding new pages
- Use consistent formatting and style
- Include practical examples
- Link to related documentation
- Add diagrams where helpful (Mermaid supported)

## Commit Messages

We follow the **Conventional Commits** specification for clear commit history.

### Format

``` text
<type>(<scope>): <subject>

<body>

<footer>
```

### Types

- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation only changes
- `style`: Code style changes (formatting, no logic change)
- `refactor`: Code refactoring (no feature change)
- `perf`: Performance improvements
- `test`: Adding or updating tests
- `build`: Build system or dependencies changes
- `ci`: CI/CD configuration changes
- `chore`: Other changes (maintenance tasks)
- `hardware`: Hardware design changes

### Scope (optional)

- `firmware`: Firmware changes
- `hardware`: Hardware changes
- `docs`: Documentation changes
- `sen5x`: SEN54 sensor module
- `t6793`: T6793 sensor module
- `nbiot`: NB-IoT module
- `rtc`: RTC module
- `config`: Configuration files

### Examples

```bash
# Simple feature
git commit -m "feat(firmware): add support for SEN55 NOx sensor"

# Bug fix with description
git commit -m "fix(nbiot): resolve HTTP timeout issue

The NB-IoT module was timing out during HTTP POST requests.
Increased timeout from 30s to 60s and added retry logic.

Fixes #123"

# Documentation update
git commit -m "docs: add firmware configuration guide"

# Breaking change
git commit -m "feat(firmware)!: change data transmission format

BREAKING CHANGE: JSON packet structure modified to include
device metadata. Server endpoint must be updated to v2 API."
```

### Rules

- Use **imperative mood** ("add" not "added" or "adds")
- Don't capitalize first letter of subject
- No period at end of subject
- Limit subject line to 50 characters
- Wrap body at 72 characters
- Use body to explain **what** and **why**, not how
- Reference issues and pull requests in footer

## Pull Request Process

### Before Submitting

- [ ] Code follows project style guidelines
- [ ] Code compiles without errors or warnings
- [ ] Changes have been tested (on hardware if applicable)
- [ ] Documentation updated (if needed)
- [ ] Commit messages follow conventions
- [ ] Branch is up to date with `main`

### PR Title

Use the same format as commit messages:

``` text
feat(firmware): add support for new sensor
```

### PR Description Template

```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix (non-breaking change fixing an issue)
- [ ] New feature (non-breaking change adding functionality)
- [ ] Breaking change (fix or feature causing existing functionality to change)
- [ ] Documentation update
- [ ] Hardware design change

## Testing
Describe testing performed:
- [ ] Compiled successfully
- [ ] Tested on hardware
- [ ] Verified sensor readings
- [ ] Checked memory usage
- [ ] Validated documentation build

## Checklist
- [ ] Code follows project style
- [ ] Self-reviewed code
- [ ] Commented complex code sections
- [ ] Updated documentation
- [ ] No new warnings generated
- [ ] Added tests (if applicable)

## Related Issues
Fixes #123
Closes #456

## Screenshots/Logs
(if applicable)
```

### Review Process

1. **Automated checks** must pass (if CI/CD configured)
2. At least **one maintainer approval** required
3. Address **review comments** promptly
4. Keep PR **focused and small** when possible
5. Be **responsive** to feedback

### Merging

- PRs are typically **squash-merged** to keep clean history
- Maintainers will merge after approval
- Delete your branch after merge

## Reporting Issues

### Bug Reports

Use the bug report template and include:

**System Information:**

- Hardware version (e.g., v2.0)
- Firmware version (e.g., commit hash)
- Arduino board (e.g., Nano 33 BLE Sense Rev2)
- Operating system (for build issues)

**Description:**

- Clear title summarizing the issue
- Detailed description of the problem
- Steps to reproduce
- Expected behavior
- Actual behavior
- Error messages or logs
- Screenshots if relevant

**Example:**

```markdown
## Bug: SEN54 sensor not responding after power cycle

**Environment:**
- Hardware: CICERONE AirLink v2.0
- Firmware: commit abc1234
- Board: Arduino Nano 33 BLE Sense Rev2

**Steps to Reproduce:**
1. Power on device
2. Wait for initialization
3. Power cycle the device
4. Observe sensor status

**Expected:** Sensor should re-initialize and start reading

**Actual:** Sensor remains unresponsive, debug shows I2C timeout

**Logs:**

```text
[ERROR][1234][SEN5X] I2C communication timeout
[ERROR][1235][SEN5X] Failed to initialize sensor
```

```markdown
```

### Feature Requests

Include:

- **Clear description** of the feature
- **Use case** - why is this needed?
- **Proposed solution** - how should it work?
- **Alternatives considered**
- **Additional context** - mockups, examples, references

## Community

### Communication Channels

- **GitHub Issues**: Bug reports and feature requests
- **GitHub Discussions**: Questions, ideas, and general discussion
- **Pull Requests**: Code contributions and reviews

### Getting Help

- Check existing documentation first
- Search closed issues for similar problems
- Ask questions in GitHub Discussions
- Be patient and respectful

### Recognition

Contributors will be:

- Listed in [AUTHORS.md](AUTHORS.md) for significant contributions
- Credited in release notes
- Acknowledged in documentation
- Thanked publicly for their work

## License

By contributing to CICERONE AirLink, you agree that your contributions will be licensed under:

- **Firmware & Software**: GNU General Public License v3.0
- **Hardware**: Creative Commons Attribution-ShareAlike 4.0 International
- **Documentation**: GNU Free Documentation License v1.3

You confirm that:

- Your contribution is your original work
- You have the right to submit the contribution
- You understand and agree to the applicable license

---

## Questions?

If you have questions about contributing, please:

1. Check this document thoroughly
2. Review existing issues and discussions
3. Open a new discussion on GitHub
4. Contact maintainers through repository channels

Thank you for contributing to CICERONE AirLink!
