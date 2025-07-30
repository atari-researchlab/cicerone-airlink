<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.7.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="1" unitdist="mm" unit="mm" style="lines" multiple="1" display="yes" altdistance="0.1" altunitdist="mm" altunit="mm"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Custom Cicerone" urn="urn:adsk.wipprod:fs.file:vf.15uM3mRNSnC6RDIQiURjTA">
<packages>
<package name="LIPO-RIDER-STAND" library_version="95">
<pad name="P$5" x="19.05" y="1.905" drill="1" shape="long" rot="R90"/>
<pad name="P$2" x="11.43" y="1.905" drill="1" shape="long" rot="R90"/>
<wire x1="7.62" y1="3.81" x2="27.94" y2="3.81" width="0.127" layer="21"/>
<wire x1="27.94" y1="3.81" x2="27.94" y2="0" width="0.127" layer="21"/>
<wire x1="7.62" y1="0" x2="7.62" y2="3.81" width="0.127" layer="21"/>
<text x="6" y="22" size="1.27" layer="25">&gt;NAME</text>
<text x="6" y="20" size="1.27" layer="27">&gt;VALUE</text>
<pad name="P$3" x="13.97" y="1.905" drill="1" shape="long" rot="R90"/>
<pad name="P$4" x="16.51" y="1.905" drill="1" shape="long" rot="R90"/>
<pad name="P$1" x="8.89" y="1.905" drill="1" shape="long" rot="R90"/>
<wire x1="0" y1="0" x2="7.62" y2="0" width="0.127" layer="21"/>
<wire x1="7.62" y1="0" x2="27.94" y2="0" width="0.127" layer="21"/>
<wire x1="27.94" y1="0" x2="41.26" y2="0" width="0.127" layer="21"/>
<wire x1="41.26" y1="0" x2="41.26" y2="25.62" width="0.127" layer="21"/>
<wire x1="41.26" y1="25.62" x2="0" y2="25.62" width="0.127" layer="21"/>
<wire x1="0" y1="25.62" x2="0" y2="0" width="0.127" layer="21"/>
<pad name="P$6" x="21.59" y="1.905" drill="1" shape="long" rot="R90"/>
<pad name="P$7" x="24.13" y="1.905" drill="1" shape="long" rot="R90"/>
<pad name="P$8" x="26.67" y="1.905" drill="1" shape="long" rot="R90"/>
<hole x="2.5" y="23.32" drill="3"/>
<text x="8.89" y="4.445" size="1.27" layer="21" rot="R90">3V3</text>
<text x="11.43" y="4.445" size="1.27" layer="21" rot="R90">EN</text>
<text x="13.97" y="4.445" size="1.27" layer="21" rot="R90">GND</text>
<text x="24.13" y="4.445" size="1.27" layer="21" rot="R90">GND</text>
<text x="19.05" y="4.445" size="1.27" layer="21" rot="R90">GND</text>
<text x="21.59" y="4.445" size="1.27" layer="21" rot="R90">BAT</text>
<text x="26.67" y="4.445" size="1.27" layer="21" rot="R90">VUSB</text>
<text x="16.51" y="4.445" size="1.27" layer="21" rot="R90">5V</text>
</package>
<package name="GROVE_SMD" library_version="95">
<smd name="NEG" x="-3" y="8.95" dx="3.3" dy="1" layer="1" rot="R270"/>
<smd name="ROJ" x="-1" y="8.95" dx="3.3" dy="1" layer="1" rot="R270"/>
<smd name="AMA" x="1" y="8.95" dx="3.3" dy="1" layer="1" rot="R270"/>
<smd name="BLA" x="3" y="8.95" dx="3.3" dy="1" layer="1" rot="R270"/>
<text x="-5.08" y="-2.54" size="1.27" layer="25">&gt;NAME</text>
<smd name="P$1" x="-5.25" y="1.9" dx="3.8" dy="1.5" layer="1" rot="R90"/>
<smd name="P$2" x="5.25" y="1.9" dx="3.8" dy="1.5" layer="1" rot="R90"/>
<wire x1="-6" y1="0" x2="-6" y2="8" width="0.127" layer="21"/>
<wire x1="-6" y1="8" x2="6" y2="8" width="0.127" layer="21"/>
<wire x1="6" y1="8" x2="6" y2="0" width="0.127" layer="21"/>
<wire x1="6" y1="0" x2="-6" y2="0" width="0.127" layer="21"/>
</package>
<package name="DS3231M-MOD-90" library_version="93">
<pad name="P$1" x="19.08" y="1.27" drill="1" shape="long" rot="R90"/>
<pad name="P$2" x="16.53" y="1.27" drill="1" shape="long" rot="R90"/>
<pad name="P$3" x="13.98" y="1.27" drill="1" shape="long" rot="R90"/>
<pad name="P$4" x="11.43" y="1.27" drill="1" shape="long" rot="R90"/>
<wire x1="0" y1="12.9" x2="20.8" y2="12.9" width="0.127" layer="21"/>
<wire x1="20.8" y1="12.9" x2="20.8" y2="6.2" width="0.127" layer="21"/>
<wire x1="20.8" y1="6.2" x2="20.8" y2="0" width="0.127" layer="21"/>
<wire x1="20.8" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<text x="9.525" y="1.905" size="1.27" layer="25" rot="SR180">&gt;NAME</text>
<wire x1="0" y1="0" x2="0" y2="9.7" width="0.127" layer="21"/>
<wire x1="0" y1="9.7" x2="0" y2="12.9" width="0.127" layer="21"/>
<wire x1="3" y1="6.2" x2="3" y2="9.7" width="0.127" layer="21" style="shortdash"/>
<wire x1="3" y1="9.7" x2="0" y2="9.7" width="0.127" layer="21" style="shortdash"/>
<wire x1="3" y1="6.2" x2="20.8" y2="6.2" width="0.127" layer="21" style="shortdash"/>
</package>
<package name="T6793" library_version="95">
<pad name="P$1" x="1.27" y="2.54" drill="1" shape="long" rot="R90"/>
<pad name="P$2" x="3.81" y="2.54" drill="1" shape="long" rot="R90"/>
<pad name="P$3" x="6.35" y="2.54" drill="1" shape="long" rot="R90"/>
<pad name="P$4" x="8.89" y="2.54" drill="1" shape="long" rot="R90"/>
<pad name="P$7" x="1.27" y="29.21" drill="1" shape="long" rot="R270"/>
<wire x1="0.257003125" y1="-0.149575" x2="0" y2="0" width="0.08" layer="21"/>
<wire x1="0" y1="0" x2="15.24" y2="0" width="0.08" layer="21"/>
<wire x1="15.24" y1="0" x2="15.24" y2="31.75" width="0.08" layer="21"/>
<wire x1="15.24" y1="31.75" x2="0" y2="31.75" width="0.08" layer="21"/>
<wire x1="0" y1="31.75" x2="0" y2="0" width="0.08" layer="21"/>
<text x="2.54" y="6.35" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<pad name="P$5" x="11.43" y="2.54" drill="1" shape="long" rot="R90"/>
<pad name="P$6" x="13.97" y="2.54" drill="1" shape="long" rot="R90"/>
</package>
<package name="I2C-HEADER" library_version="95">
<pad name="VCC" x="6.35" y="2.54" drill="1" shape="long" rot="R90"/>
<pad name="GND" x="8.89" y="2.54" drill="1" shape="long" rot="R90"/>
<pad name="SDA" x="1.27" y="2.54" drill="1" shape="long" rot="R90"/>
<pad name="SCL" x="3.81" y="2.54" drill="1" shape="long" rot="R90"/>
<wire x1="0" y1="0" x2="0" y2="5.08" width="0.127" layer="21"/>
<wire x1="0" y1="5.08" x2="10.16" y2="5.08" width="0.127" layer="21"/>
<wire x1="10.16" y1="5.08" x2="10.16" y2="0" width="0.127" layer="21"/>
<wire x1="10.16" y1="0" x2="0" y2="0" width="0.127" layer="21"/>
<text x="1.27" y="6.35" size="1.27" layer="25">&gt;NAME</text>
<text x="1.27" y="-0.635" size="1.27" layer="21" rot="R90" align="center-right">SDA</text>
<text x="3.81" y="-0.635" size="1.27" layer="21" rot="R90" align="center-right">SCL</text>
<text x="6.35" y="-0.635" size="1.27" layer="21" rot="R90" align="center-right">VCC</text>
<text x="8.89" y="-0.635" size="1.27" layer="21" rot="R90" align="center-right">GND</text>
</package>
<package name="PIN2X1" library_version="95">
<pad name="P$1" x="1.27" y="1.905" drill="1" shape="long" rot="R90"/>
<pad name="P$2" x="3.81" y="1.905" drill="1" shape="long" rot="R90"/>
<wire x1="0" y1="0" x2="5.08" y2="0" width="0.127" layer="21"/>
<wire x1="5.08" y1="0" x2="5.08" y2="3.81" width="0.127" layer="21"/>
<wire x1="5.08" y1="3.81" x2="0" y2="3.81" width="0.127" layer="21" locked="yes"/>
<wire x1="0" y1="3.81" x2="0" y2="0" width="0.127" layer="21"/>
<text x="1.27" y="4.445" size="1.27" layer="27" rot="SR0">&gt;VALUE</text>
</package>
<package name="USB-SWITCH" library_version="95">
<pad name="P$1" x="8.89" y="1.27" drill="1" shape="long" rot="R90"/>
<pad name="P$2" x="6.35" y="1.27" drill="1" shape="long" rot="R90"/>
<wire x1="0" y1="0" x2="10.16" y2="0" width="0.127" layer="21"/>
<wire x1="10.16" y1="0" x2="10.16" y2="8.255" width="0.127" layer="21"/>
<wire x1="10.16" y1="8.255" x2="0" y2="8.255" width="0.127" layer="21"/>
<wire x1="0" y1="8.255" x2="0" y2="0" width="0.127" layer="21"/>
<text x="3.81" y="-1.27" size="1.27" layer="21" rot="SR180" align="center">+</text>
<text x="8.89" y="-1.27" size="1.27" layer="21" rot="SR180" align="center">-</text>
<text x="7.62" y="-1.905" size="0.762" layer="21" rot="SR180" align="bottom-center">Vin</text>
<pad name="P$3" x="3.81" y="1.27" drill="1" shape="long" rot="R90"/>
<pad name="P$4" x="1.27" y="1.27" drill="1" shape="long" rot="R90"/>
<text x="6.35" y="-1.27" size="1.27" layer="21" rot="SR180" align="center">+</text>
<text x="1.27" y="-1.27" size="0.762" layer="21" rot="SR180" align="center">EN</text>
<text x="2.54" y="-1.905" size="0.762" layer="21" rot="SR180" align="bottom-center">SWT</text>
</package>
</packages>
<symbols>
<symbol name="LIPO-RIDER" library_version="88">
<pin name="5V" x="-5" y="8" visible="pin" length="middle" direction="sup"/>
<wire x1="0" y1="19" x2="12" y2="19" width="0.254" layer="94"/>
<wire x1="12" y1="19" x2="12" y2="0" width="0.254" layer="94"/>
<wire x1="12" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="19" width="0.254" layer="94"/>
<text x="1" y="20" size="1.27" layer="95">&gt;NAME</text>
<pin name="BAT" x="-5" y="17" visible="pin" length="middle" direction="sup"/>
<pin name="GND" x="-5" y="2" visible="pin" length="middle" direction="sup"/>
<pin name="USB" x="-5" y="14" visible="pin" length="middle" direction="sup"/>
<pin name="EN" x="-5" y="11" visible="pin" length="middle" direction="in"/>
<pin name="3V3" x="-5" y="5" visible="pin" length="middle" direction="sup"/>
</symbol>
<symbol name="GROVE-UART" library_version="93">
<pin name="GND" x="-5" y="8" visible="pin" length="middle" direction="sup"/>
<pin name="5V" x="-5" y="11" visible="pin" length="middle" direction="sup"/>
<pin name="RX" x="-5" y="5" visible="pin" length="middle"/>
<pin name="TX" x="-5" y="2" visible="pin" length="middle"/>
<text x="1" y="14" size="1.778" layer="95">&gt;NAME</text>
<wire x1="0" y1="0" x2="9" y2="0" width="0.254" layer="94"/>
<wire x1="9" y1="0" x2="9" y2="13" width="0.254" layer="94"/>
<wire x1="9" y1="13" x2="0" y2="13" width="0.254" layer="94"/>
<wire x1="0" y1="13" x2="0" y2="0" width="0.254" layer="94"/>
</symbol>
<symbol name="I2C-HEADER" library_version="91">
<wire x1="9" y1="13" x2="0" y2="13" width="0.254" layer="94"/>
<wire x1="0" y1="13" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="9" y2="0" width="0.254" layer="94"/>
<wire x1="9" y1="0" x2="9" y2="13" width="0.254" layer="94"/>
<pin name="VCC" x="-5" y="11" visible="pin" length="middle" direction="sup"/>
<pin name="GND" x="-5" y="8" visible="pin" length="middle" direction="sup"/>
<pin name="SCL" x="-5" y="5" visible="pin" length="middle"/>
<pin name="SDA" x="-5" y="2" visible="pin" length="middle"/>
<text x="1" y="14" size="1.27" layer="95">&gt;NAME</text>
</symbol>
<symbol name="T6793" library_version="91">
<description>&lt;b&gt;Amphenol Telaire CO2 Sensor T6793&lt;/b&gt;
&lt;ol&gt;
&lt;li&gt;TX/SDA&lt;/li&gt;
&lt;li&gt;RX/SCL&lt;/li&gt;
&lt;li&gt;VCC (5V)&lt;/li&gt;
&lt;li&gt;GND&lt;/li&gt;
&lt;li&gt;PWM Output. Requires external pull-up&lt;/li&gt;
&lt;li&gt;SEL: Select interface mode
&lt;ul&gt;
&lt;li&gt;RS232@19600bps &amp; PWM@1Hz: NC&lt;/li&gt;
&lt;li&gt;I2C@100kHz &amp; PWM@25kHz: GND&lt;/li&gt;
&lt;li&gt;RS485: 10k-100k pull-down. Controls data direction. Pin5 should be NC&lt;/li&gt;
&lt;/ul&gt;
&lt;/li&gt;
&lt;/ol&gt;</description>
<pin name="SDA" x="-5" y="17" visible="pin" length="middle"/>
<pin name="SCL" x="-5" y="14" visible="pin" length="middle"/>
<pin name="VCC" x="-5" y="5" visible="pin" length="middle" direction="sup"/>
<pin name="GND" x="-5" y="2" visible="pin" length="middle" direction="sup"/>
<wire x1="0" y1="19" x2="14" y2="19" width="0.2" layer="94"/>
<wire x1="14" y1="19" x2="14" y2="0" width="0.2" layer="94"/>
<wire x1="14" y1="0" x2="0" y2="0" width="0.2" layer="94"/>
<wire x1="0" y1="0" x2="0" y2="19" width="0.2" layer="94"/>
<text x="1" y="20" size="1.778" layer="95">&gt;NAME</text>
<pin name="NC" x="19" y="16" visible="pin" length="middle" direction="nc" rot="R180"/>
<pin name="PWM" x="-5" y="8" visible="pin" length="middle"/>
<pin name="SEL" x="-5" y="11" visible="pin" length="middle"/>
</symbol>
<symbol name="CURR-MEAS" library_version="94">
<pin name="5VOUT" x="-5" y="5" visible="pin" length="middle" direction="sup"/>
<pin name="5VIN" x="-5" y="2" visible="pin" length="middle" direction="sup"/>
<wire x1="0" y1="7" x2="10" y2="7" width="0.2" layer="94"/>
<wire x1="0" y1="7" x2="0" y2="0" width="0.2" layer="94"/>
<wire x1="0" y1="0" x2="10" y2="0" width="0.2" layer="94"/>
<wire x1="10" y1="0" x2="10" y2="7" width="0.2" layer="94"/>
<text x="1" y="8" size="1.27" layer="95">&gt;NAME</text>
</symbol>
<symbol name="USB-SWITCH" library_version="91">
<pin name="GND" x="-5" y="8" visible="pin" length="middle" direction="sup"/>
<pin name="VUSB" x="-5" y="5" visible="pin" length="middle" direction="sup"/>
<wire x1="0" y1="10" x2="10" y2="10" width="0.2" layer="94"/>
<wire x1="0" y1="10" x2="0" y2="0" width="0.2" layer="94"/>
<wire x1="0" y1="0" x2="10" y2="0" width="0.2" layer="94"/>
<wire x1="10" y1="0" x2="10" y2="10" width="0.2" layer="94"/>
<text x="1" y="11" size="1.27" layer="95">&gt;NAME</text>
<pin name="EN" x="-5" y="2" visible="pin" length="middle" direction="out"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="LIPO-RIDER" prefix="LIPO-RIDER" library_version="95">
<gates>
<gate name="G$1" symbol="LIPO-RIDER" x="5.08" y="-12.7"/>
</gates>
<devices>
<device name="" package="LIPO-RIDER-STAND">
<connects>
<connect gate="G$1" pin="3V3" pad="P$1"/>
<connect gate="G$1" pin="5V" pad="P$4"/>
<connect gate="G$1" pin="BAT" pad="P$6"/>
<connect gate="G$1" pin="EN" pad="P$2"/>
<connect gate="G$1" pin="GND" pad="P$3 P$5 P$7"/>
<connect gate="G$1" pin="USB" pad="P$8"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="GROVE-UART" prefix="GROVE-UART" library_version="95">
<gates>
<gate name="G$1" symbol="GROVE-UART" x="-2.54" y="0"/>
</gates>
<devices>
<device name="SMD" package="GROVE_SMD">
<connects>
<connect gate="G$1" pin="5V" pad="ROJ"/>
<connect gate="G$1" pin="GND" pad="NEG P$1 P$2"/>
<connect gate="G$1" pin="RX" pad="AMA"/>
<connect gate="G$1" pin="TX" pad="BLA"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="RTC-DS3231M" prefix="RTC" library_version="95">
<gates>
<gate name="G$1" symbol="I2C-HEADER" x="0" y="0"/>
</gates>
<devices>
<device name="MOD-90" package="DS3231M-MOD-90">
<connects>
<connect gate="G$1" pin="GND" pad="P$2"/>
<connect gate="G$1" pin="SCL" pad="P$3"/>
<connect gate="G$1" pin="SDA" pad="P$4"/>
<connect gate="G$1" pin="VCC" pad="P$1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="T6793" prefix="T6793" library_version="95">
<gates>
<gate name="G$1" symbol="T6793" x="-2.54" y="15.24"/>
</gates>
<devices>
<device name="" package="T6793">
<connects>
<connect gate="G$1" pin="GND" pad="P$4"/>
<connect gate="G$1" pin="NC" pad="P$7"/>
<connect gate="G$1" pin="PWM" pad="P$5"/>
<connect gate="G$1" pin="SCL" pad="P$2"/>
<connect gate="G$1" pin="SDA" pad="P$1"/>
<connect gate="G$1" pin="SEL" pad="P$6"/>
<connect gate="G$1" pin="VCC" pad="P$3"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="I2C-HEADER" prefix="I2C-" library_version="95">
<gates>
<gate name="G$1" symbol="I2C-HEADER" x="-10.16" y="15.24"/>
</gates>
<devices>
<device name="" package="I2C-HEADER">
<connects>
<connect gate="G$1" pin="GND" pad="GND"/>
<connect gate="G$1" pin="SCL" pad="SCL"/>
<connect gate="G$1" pin="SDA" pad="SDA"/>
<connect gate="G$1" pin="VCC" pad="VCC"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="CURR-MEAS" prefix="CURR-MEAS" uservalue="yes" library_version="95">
<gates>
<gate name="G$1" symbol="CURR-MEAS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="PIN2X1">
<connects>
<connect gate="G$1" pin="5VIN" pad="P$2"/>
<connect gate="G$1" pin="5VOUT" pad="P$1"/>
</connects>
<technologies>
<technology name="">
<attribute name="VALUE" value="I→"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="USB_SWITCH" prefix="USB-SWITCH" library_version="95">
<gates>
<gate name="G$1" symbol="USB-SWITCH" x="0" y="0"/>
</gates>
<devices>
<device name="" package="USB-SWITCH">
<connects>
<connect gate="G$1" pin="EN" pad="P$4"/>
<connect gate="G$1" pin="GND" pad="P$1"/>
<connect gate="G$1" pin="VUSB" pad="P$2 P$3" route="any"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="testpad" urn="urn:adsk.wipprod:fs.file:vf.3lHXDImfT4KV5U3V6H2GRQ">
<description>&lt;b&gt;Test Pins/Pads&lt;/b&gt;&lt;p&gt;
Cream on SMD OFF.&lt;br&gt;
new: Attribute TP_SIGNAL_NAME&lt;br&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="B1,27" urn="urn:adsk.eagle:footprint:27900/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<wire x1="-0.635" y1="0" x2="0.635" y2="0" width="0.0024" layer="37"/>
<wire x1="0" y1="0.635" x2="0" y2="-0.635" width="0.0024" layer="37"/>
<smd name="TP" x="0" y="0" dx="1.27" dy="1.27" layer="1" roundness="100" cream="no"/>
<text x="-0.635" y="1.016" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-0.635" y="-0.762" size="0.0254" layer="27">&gt;VALUE</text>
<text x="-0.635" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="B2,54" urn="urn:adsk.eagle:footprint:27901/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<wire x1="-0.635" y1="0" x2="0.635" y2="0" width="0.0024" layer="37"/>
<wire x1="0" y1="-0.635" x2="0" y2="0.635" width="0.0024" layer="37"/>
<circle x="0" y="0" radius="0.635" width="0.254" layer="37"/>
<smd name="TP" x="0" y="0" dx="2.54" dy="2.54" layer="1" roundness="100" cream="no"/>
<text x="-1.27" y="1.651" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-1.397" size="0.0254" layer="27">&gt;VALUE</text>
<text x="-1.27" y="-3.175" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="P1-13" urn="urn:adsk.eagle:footprint:27902/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<circle x="0" y="0" radius="0.762" width="0.1524" layer="51"/>
<pad name="TP" x="0" y="0" drill="1.3208" diameter="2.159" shape="octagon"/>
<text x="-1.016" y="1.27" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="0" size="0.0254" layer="27">&gt;VALUE</text>
<text x="-1.27" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
<rectangle x1="-0.3302" y1="-0.3302" x2="0.3302" y2="0.3302" layer="51"/>
</package>
<package name="P1-13Y" urn="urn:adsk.eagle:footprint:27903/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<circle x="0" y="0" radius="0.762" width="0.1524" layer="51"/>
<pad name="TP" x="0" y="0" drill="1.3208" diameter="1.905" shape="long" rot="R90"/>
<text x="-0.889" y="2.159" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="0" size="0.0254" layer="27">&gt;VALUE</text>
<text x="-1.27" y="-3.81" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
<rectangle x1="-0.3302" y1="-0.3302" x2="0.3302" y2="0.3302" layer="51"/>
</package>
<package name="P1-17" urn="urn:adsk.eagle:footprint:27904/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<circle x="0" y="0" radius="0.8128" width="0.1524" layer="51"/>
<pad name="TP" x="0" y="0" drill="1.7018" diameter="2.54" shape="octagon"/>
<text x="-1.143" y="1.397" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="0" size="0.0254" layer="27">&gt;VALUE</text>
<text x="-1.27" y="-3.175" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
<rectangle x1="-0.3302" y1="-0.3302" x2="0.3302" y2="0.3302" layer="51"/>
</package>
<package name="P1-17Y" urn="urn:adsk.eagle:footprint:27905/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<circle x="0" y="0" radius="0.8128" width="0.1524" layer="51"/>
<pad name="TP" x="0" y="0" drill="1.7018" diameter="2.1208" shape="long" rot="R90"/>
<text x="-1.143" y="2.286" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="0" size="0.0254" layer="27">&gt;VALUE</text>
<text x="-1.27" y="-3.81" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
<rectangle x1="-0.3302" y1="-0.3302" x2="0.3302" y2="0.3302" layer="51"/>
</package>
<package name="P1-20" urn="urn:adsk.eagle:footprint:27906/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<circle x="0" y="0" radius="1.016" width="0.1524" layer="51"/>
<pad name="TP" x="0" y="0" drill="2.0066" diameter="3.1496" shape="octagon"/>
<text x="-1.524" y="1.778" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="0" size="0.0254" layer="27">&gt;VALUE</text>
<text x="-1.27" y="-3.175" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
<rectangle x1="-0.3302" y1="-0.3302" x2="0.3302" y2="0.3302" layer="51"/>
</package>
<package name="P1-20Y" urn="urn:adsk.eagle:footprint:27907/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<circle x="0" y="0" radius="1.016" width="0.1524" layer="51"/>
<pad name="TP" x="0" y="0" drill="2.0066" diameter="2.54" shape="long" rot="R90"/>
<text x="-1.27" y="2.794" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="0" y="0" size="0.0254" layer="27">&gt;VALUE</text>
<text x="-1.27" y="-4.445" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
<rectangle x1="-0.3302" y1="-0.3302" x2="0.3302" y2="0.3302" layer="51"/>
</package>
<package name="TP06R" urn="urn:adsk.eagle:footprint:27908/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="0.6" dy="0.6" layer="1" roundness="100" cream="no"/>
<text x="-0.3" y="0.4001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.254" y="-0.381" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP06SQ" urn="urn:adsk.eagle:footprint:27909/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="0.5996" dy="0.5996" layer="1" cream="no"/>
<text x="-0.3" y="0.4001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.254" y="-0.381" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP07R" urn="urn:adsk.eagle:footprint:27910/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="0.7" dy="0.7" layer="1" roundness="100" cream="no"/>
<text x="-0.3" y="0.4001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.254" y="-0.508" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP07SQ" urn="urn:adsk.eagle:footprint:27911/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="0.7" dy="0.7" layer="1" cream="no"/>
<text x="-0.3" y="0.4001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.381" y="-0.381" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP08R" urn="urn:adsk.eagle:footprint:27912/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="0.8" dy="0.8" layer="1" roundness="100" cream="no"/>
<text x="-0.3" y="0.4001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.381" y="-0.381" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP08SQ" urn="urn:adsk.eagle:footprint:27913/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="0.8" dy="0.8" layer="1" cream="no"/>
<text x="-0.3" y="0.4001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.381" y="-0.508" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP09R" urn="urn:adsk.eagle:footprint:27914/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="0.9" dy="0.9" layer="1" roundness="100" cream="no"/>
<text x="-0.4501" y="0.5001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.381" y="-0.508" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP09SQ" urn="urn:adsk.eagle:footprint:27915/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="0.8998" dy="0.8998" layer="1" cream="no"/>
<text x="-0.4501" y="0.5001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.381" y="-0.508" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP10R" urn="urn:adsk.eagle:footprint:27916/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1" dy="1" layer="1" roundness="100" cream="no"/>
<text x="-0.5001" y="0.5499" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.381" y="-0.508" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP10SQ" urn="urn:adsk.eagle:footprint:27917/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1" dy="1" layer="1" cream="no"/>
<text x="-0.5001" y="0.5499" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.508" y="-0.635" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP11R" urn="urn:adsk.eagle:footprint:27918/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.1" dy="1.1" layer="1" roundness="100" cream="no"/>
<text x="-0.5499" y="0.5999" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.508" y="-0.508" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-1.905" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP11SQ" urn="urn:adsk.eagle:footprint:27919/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.1" dy="1.1" layer="1" cream="no"/>
<text x="-0.5499" y="0.5999" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.508" y="-0.635" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP12SQ" urn="urn:adsk.eagle:footprint:27920/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.1998" dy="1.1998" layer="1" cream="no"/>
<text x="-0.5999" y="0.65" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.508" y="-0.635" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP12R" urn="urn:adsk.eagle:footprint:27921/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.2" dy="1.2" layer="1" roundness="100" cream="no"/>
<text x="-0.5999" y="0.65" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.508" y="-0.635" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP13R" urn="urn:adsk.eagle:footprint:27922/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.3" dy="1.3" layer="1" roundness="100" cream="no"/>
<text x="-0.65" y="0.7" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.508" y="-0.635" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP14R" urn="urn:adsk.eagle:footprint:27923/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.4" dy="1.4" layer="1" roundness="100" cream="no"/>
<text x="-0.7" y="0.7501" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.508" y="-0.762" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP15R" urn="urn:adsk.eagle:footprint:27924/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.5" dy="1.5" layer="1" roundness="100" cream="no"/>
<text x="-0.7501" y="0.8001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.635" y="-0.762" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP16R" urn="urn:adsk.eagle:footprint:27925/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.6" dy="1.6" layer="1" roundness="100" cream="no"/>
<text x="-0.8001" y="0.8499" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.635" y="-0.762" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP17R" urn="urn:adsk.eagle:footprint:27926/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.7" dy="1.7" layer="1" roundness="100" cream="no"/>
<text x="-0.8499" y="0.8999" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.635" y="-0.889" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP18R" urn="urn:adsk.eagle:footprint:27927/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.8" dy="1.8" layer="1" roundness="100" cream="no"/>
<text x="-0.8999" y="0.95" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.762" y="-0.889" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP19R" urn="urn:adsk.eagle:footprint:27928/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.9" dy="1.9" layer="1" roundness="100" cream="no"/>
<text x="-0.95" y="1" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.762" y="-0.889" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP20R" urn="urn:adsk.eagle:footprint:27929/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="2" dy="2" layer="1" roundness="100" cream="no"/>
<text x="-1" y="1.05" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.762" y="-1.016" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP13SQ" urn="urn:adsk.eagle:footprint:27930/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.3" dy="1.3" layer="1" cream="no"/>
<text x="-0.65" y="0.7" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.635" y="-0.762" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP14SQ" urn="urn:adsk.eagle:footprint:27931/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.4" dy="1.4" layer="1" cream="no"/>
<text x="-0.7" y="0.7501" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.635" y="-0.762" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP15SQ" urn="urn:adsk.eagle:footprint:27932/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.5" dy="1.5" layer="1" cream="no"/>
<text x="-0.7501" y="0.8001" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.762" y="-0.889" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP16SQ" urn="urn:adsk.eagle:footprint:27933/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.5996" dy="1.5996" layer="1" cream="no"/>
<text x="-0.8001" y="0.8499" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.762" y="-0.889" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP17SQ" urn="urn:adsk.eagle:footprint:27934/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.7" dy="1.7" layer="1" cream="no"/>
<text x="-0.8499" y="0.8999" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.762" y="-0.889" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP18SQ" urn="urn:adsk.eagle:footprint:27935/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.8" dy="1.8" layer="1" cream="no"/>
<text x="-0.8999" y="0.95" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.889" y="-1.016" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP19SQ" urn="urn:adsk.eagle:footprint:27936/1" library_version="3">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="1.8998" dy="1.8998" layer="1" cream="no"/>
<text x="-0.95" y="1" size="1.27" layer="25">&gt;NAME</text>
<text x="-0.889" y="-1.016" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
<package name="TP20SQ" urn="urn:adsk.eagle:footprint:27937/1" library_version="1">
<description>&lt;b&gt;TEST PAD&lt;/b&gt;</description>
<smd name="TP" x="0" y="0" dx="2" dy="2" layer="1" cream="no"/>
<text x="-1" y="1.05" size="1.27" layer="25">&gt;NAME</text>
<text x="-1.016" y="-1.143" size="0.0254" layer="27">&gt;VALUE</text>
<text x="0" y="-2.54" size="1" layer="37">&gt;TP_SIGNAL_NAME</text>
</package>
</packages>
<packages3d>
<package3d name="B1,27" urn="urn:adsk.eagle:package:27944/2" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="B1,27"/>
</packageinstances>
</package3d>
<package3d name="B2,54" urn="urn:adsk.eagle:package:27948/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="B2,54"/>
</packageinstances>
</package3d>
<package3d name="P1-13" urn="urn:adsk.eagle:package:27946/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="P1-13"/>
</packageinstances>
</package3d>
<package3d name="P1-13Y" urn="urn:adsk.eagle:package:27947/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="P1-13Y"/>
</packageinstances>
</package3d>
<package3d name="P1-17" urn="urn:adsk.eagle:package:27949/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="P1-17"/>
</packageinstances>
</package3d>
<package3d name="P1-17Y" urn="urn:adsk.eagle:package:27953/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="P1-17Y"/>
</packageinstances>
</package3d>
<package3d name="P1-20" urn="urn:adsk.eagle:package:27950/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="P1-20"/>
</packageinstances>
</package3d>
<package3d name="P1-20Y" urn="urn:adsk.eagle:package:27951/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="P1-20Y"/>
</packageinstances>
</package3d>
<package3d name="TP06R" urn="urn:adsk.eagle:package:27954/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP06R"/>
</packageinstances>
</package3d>
<package3d name="TP06SQ" urn="urn:adsk.eagle:package:27952/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP06SQ"/>
</packageinstances>
</package3d>
<package3d name="TP07R" urn="urn:adsk.eagle:package:27970/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP07R"/>
</packageinstances>
</package3d>
<package3d name="TP07SQ" urn="urn:adsk.eagle:package:27955/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP07SQ"/>
</packageinstances>
</package3d>
<package3d name="TP08R" urn="urn:adsk.eagle:package:27956/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP08R"/>
</packageinstances>
</package3d>
<package3d name="TP08SQ" urn="urn:adsk.eagle:package:27960/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP08SQ"/>
</packageinstances>
</package3d>
<package3d name="TP09R" urn="urn:adsk.eagle:package:27958/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP09R"/>
</packageinstances>
</package3d>
<package3d name="TP09SQ" urn="urn:adsk.eagle:package:27957/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP09SQ"/>
</packageinstances>
</package3d>
<package3d name="TP10R" urn="urn:adsk.eagle:package:27959/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP10R"/>
</packageinstances>
</package3d>
<package3d name="TP10SQ" urn="urn:adsk.eagle:package:27962/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP10SQ"/>
</packageinstances>
</package3d>
<package3d name="TP11R" urn="urn:adsk.eagle:package:27961/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP11R"/>
</packageinstances>
</package3d>
<package3d name="TP11SQ" urn="urn:adsk.eagle:package:27965/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP11SQ"/>
</packageinstances>
</package3d>
<package3d name="TP12SQ" urn="urn:adsk.eagle:package:27964/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP12SQ"/>
</packageinstances>
</package3d>
<package3d name="TP12R" urn="urn:adsk.eagle:package:27963/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP12R"/>
</packageinstances>
</package3d>
<package3d name="TP13R" urn="urn:adsk.eagle:package:27967/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP13R"/>
</packageinstances>
</package3d>
<package3d name="TP14R" urn="urn:adsk.eagle:package:27966/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP14R"/>
</packageinstances>
</package3d>
<package3d name="TP15R" urn="urn:adsk.eagle:package:27968/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP15R"/>
</packageinstances>
</package3d>
<package3d name="TP16R" urn="urn:adsk.eagle:package:27969/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP16R"/>
</packageinstances>
</package3d>
<package3d name="TP17R" urn="urn:adsk.eagle:package:27971/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP17R"/>
</packageinstances>
</package3d>
<package3d name="TP18R" urn="urn:adsk.eagle:package:27981/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP18R"/>
</packageinstances>
</package3d>
<package3d name="TP19R" urn="urn:adsk.eagle:package:27972/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP19R"/>
</packageinstances>
</package3d>
<package3d name="TP20R" urn="urn:adsk.eagle:package:27973/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP20R"/>
</packageinstances>
</package3d>
<package3d name="TP13SQ" urn="urn:adsk.eagle:package:27974/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP13SQ"/>
</packageinstances>
</package3d>
<package3d name="TP14SQ" urn="urn:adsk.eagle:package:27984/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP14SQ"/>
</packageinstances>
</package3d>
<package3d name="TP15SQ" urn="urn:adsk.eagle:package:27975/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP15SQ"/>
</packageinstances>
</package3d>
<package3d name="TP16SQ" urn="urn:adsk.eagle:package:27976/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP16SQ"/>
</packageinstances>
</package3d>
<package3d name="TP17SQ" urn="urn:adsk.eagle:package:27977/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP17SQ"/>
</packageinstances>
</package3d>
<package3d name="TP18SQ" urn="urn:adsk.eagle:package:27979/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP18SQ"/>
</packageinstances>
</package3d>
<package3d name="TP19SQ" urn="urn:adsk.eagle:package:27978/1" type="box">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP19SQ"/>
</packageinstances>
</package3d>
<package3d name="TP20SQ" urn="urn:adsk.eagle:package:27980/1" locally_modified="yes" type="model">
<description>TEST PAD</description>
<packageinstances>
<packageinstance name="TP20SQ"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="PS" urn="urn:adsk.eagle:symbol:27897/1" library_version="3">
<wire x1="0.635" y1="-4.572" x2="-0.635" y2="-4.572" width="0.1524" layer="94"/>
<wire x1="0.635" y1="-4.572" x2="0.635" y2="0" width="0.1524" layer="94"/>
<wire x1="0.635" y1="0" x2="-0.635" y2="0" width="0.1524" layer="94"/>
<wire x1="-0.635" y1="0" x2="-0.635" y2="-4.572" width="0.1524" layer="94"/>
<wire x1="0.381" y1="-3.048" x2="-0.381" y2="-2.794" width="0.1524" layer="94"/>
<wire x1="-0.381" y1="-2.794" x2="0.381" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="0.381" y1="-2.54" x2="-0.381" y2="-2.286" width="0.1524" layer="94"/>
<wire x1="-0.381" y1="-2.286" x2="0.381" y2="-2.032" width="0.1524" layer="94"/>
<wire x1="0.381" y1="-2.032" x2="-0.381" y2="-1.778" width="0.1524" layer="94"/>
<wire x1="-0.381" y1="-1.778" x2="0.381" y2="-1.524" width="0.1524" layer="94"/>
<wire x1="0.381" y1="-1.524" x2="-0.381" y2="-1.27" width="0.1524" layer="94"/>
<wire x1="-0.381" y1="-1.27" x2="0.381" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="0.381" y1="-1.016" x2="-0.381" y2="-0.762" width="0.1524" layer="94"/>
<wire x1="-0.381" y1="-0.762" x2="0.381" y2="-0.508" width="0.1524" layer="94"/>
<wire x1="0.508" y1="-5.207" x2="-0.508" y2="-5.207" width="0.1524" layer="94"/>
<wire x1="-0.508" y1="-5.207" x2="-0.508" y2="-5.715" width="0.1524" layer="94"/>
<wire x1="-0.508" y1="-5.715" x2="0" y2="-6.35" width="0.1524" layer="94"/>
<wire x1="0" y1="-6.35" x2="0.508" y2="-5.715" width="0.1524" layer="94"/>
<wire x1="0.508" y1="-5.715" x2="0.508" y2="-5.207" width="0.1524" layer="94"/>
<text x="-1.016" y="-6.35" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="1.27" y="-2.54" size="1.778" layer="97">&gt;TP_SIGNAL_NAME</text>
<rectangle x1="-0.381" y1="-5.207" x2="0.381" y2="-4.572" layer="94"/>
<pin name="TP" x="0" y="2.54" visible="off" length="short" direction="in" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PTR1" urn="urn:adsk.eagle:component:27989/3" prefix="TP" library_version="1" library_locally_modified="yes">
<description>&lt;b&gt;TEST PIN&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PS" x="0" y="0"/>
</gates>
<devices>
<device name="B1,27" package="B1,27">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27944/2"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="2" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="B2,54" package="B2,54">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27948/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="PAD1-13" package="P1-13">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27946/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="2" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="PAD1-13Y" package="P1-13Y">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27947/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="1" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="PAD1-17" package="P1-17">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27949/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="PAD1-17Y" package="P1-17Y">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27953/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="PAD1-20" package="P1-20">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27950/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="3" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="PAD1-20Y" package="P1-20Y">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27951/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="1" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP06R" package="TP06R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27954/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="1" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP06SQ" package="TP06SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27952/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP07R" package="TP07R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27970/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP07SQ" package="TP07SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27955/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP08R" package="TP08R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27956/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP08SQ" package="TP08SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27960/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP09R" package="TP09R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27958/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="1" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP09SQ" package="TP09SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27957/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP10R" package="TP10R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27959/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP10SQ" package="TP10SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27962/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP11R" package="TP11R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27961/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="1" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP11SQ" package="TP11SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27965/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP12SQ" package="TP12SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27964/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP12R" package="TP12R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27963/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP13R" package="TP13R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27967/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="1" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP14R" package="TP14R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27966/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="1" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP15R" package="TP15R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27968/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP16R" package="TP16R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27969/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP17R" package="TP17R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27971/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP18R" package="TP18R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27981/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP19R" package="TP19R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27972/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP20R" package="TP20R">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27973/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP13SQ" package="TP13SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27974/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP14SQ" package="TP14SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27984/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP15SQ" package="TP15SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27975/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP16SQ" package="TP16SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27976/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP17SQ" package="TP17SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27977/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP18SQ" package="TP18SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27979/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP19SQ" package="TP19SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27978/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
<device name="TP20SQ" package="TP20SQ">
<connects>
<connect gate="G$1" pin="TP" pad="TP"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:27980/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="POPULARITY" value="0" constant="no"/>
<attribute name="TP_SIGNAL_NAME" value="" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="ArduinoNano" urn="urn:adsk.wipprod:fs.file:vf.yiiWTITUTr2LdZfMQMe1SA">
<packages>
<package name="NANO_BLE33_SMT" library_version="19">
<description>&lt;b&gt;Arduino Nano V3.0&lt;/b&gt;&lt;br&gt;
&lt;p&gt;The Nano was designed and is being produced by Gravitech.&lt;br&gt;

&lt;a href="http://www.gravitech.us/arna30wiatp.html"&gt;Gravitech Arduino Nano V3.0&lt;/a&gt;&lt;/p&gt;</description>
<hole x="-22.86" y="-7.62" drill="1.778"/>
<pad name="1" x="-20.32" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="2" x="-17.78" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="3" x="-15.24" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="4" x="-12.7" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="5" x="-10.16" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="6" x="-7.62" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="7" x="-5.08" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="8" x="-2.54" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="9" x="0" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="10" x="2.54" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="11" x="5.08" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="12" x="7.62" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="13" x="10.16" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="14" x="12.7" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="15" x="15.24" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="16" x="15.24" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="17" x="12.7" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="18" x="10.16" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="19" x="7.62" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="20" x="5.08" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="21" x="2.54" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="22" x="0" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="23" x="-2.54" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="24" x="-5.08" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="25" x="-7.62" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="26" x="-10.16" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="27" x="-12.7" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="28" x="-15.24" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="29" x="-17.78" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="30" x="-20.32" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<hole x="-22.86" y="7.62" drill="1.778"/>
<hole x="17.78" y="7.62" drill="1.778"/>
<hole x="17.78" y="-7.62" drill="1.778"/>
<wire x1="-24.13" y1="8.89" x2="19.05" y2="8.89" width="0.127" layer="21"/>
<wire x1="19.05" y1="8.89" x2="19.05" y2="-8.89" width="0.127" layer="21"/>
<wire x1="19.05" y1="-8.89" x2="-24.13" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-24.13" y1="-8.89" x2="-24.13" y2="2.54" width="0.127" layer="21"/>
<wire x1="-24.13" y1="2.54" x2="-24.13" y2="8.89" width="0.127" layer="21"/>
<wire x1="-24.13" y1="2.54" x2="-25.4" y2="2.54" width="0.127" layer="21"/>
<wire x1="-25.4" y1="2.54" x2="-25.4" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-19.05" y1="-2.54" x2="-19.05" y2="2.54" width="0.127" layer="21"/>
<wire x1="-19.05" y1="2.54" x2="-24.13" y2="2.54" width="0.127" layer="21"/>
<wire x1="-19.05" y1="-2.54" x2="-25.4" y2="-2.54" width="0.127" layer="21"/>
<text x="-17.78" y="2.54" size="1.27" layer="21" font="vector">&gt;NAME</text>
<text x="-17.78" y="-5.08" size="1.27" layer="21" font="vector">&gt;VALUE</text>
<text x="-20.32" y="-6.35" size="1.016" layer="21" font="vector">1</text>
</package>
<package name="NANO_BLE33_PIN" library_version="26">
<description>&lt;b&gt;Arduino Nano V3.0&lt;/b&gt;&lt;br&gt;
&lt;p&gt;The Nano was designed and is being produced by Gravitech.&lt;br&gt;

&lt;a href="http://www.gravitech.us/arna30wiatp.html"&gt;Gravitech Arduino Nano V3.0&lt;/a&gt;&lt;/p&gt;</description>
<hole x="-22.86" y="-7.62" drill="1.778"/>
<pad name="1" x="-20.32" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="2" x="-17.78" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="3" x="-15.24" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="4" x="-12.7" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="5" x="-10.16" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="6" x="-7.62" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="7" x="-5.08" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="8" x="-2.54" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="9" x="0" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="10" x="2.54" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="11" x="5.08" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="12" x="7.62" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="13" x="10.16" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="14" x="12.7" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="15" x="15.24" y="-7.62" drill="0.8" shape="offset" rot="R270"/>
<pad name="16" x="15.24" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="17" x="12.7" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="18" x="10.16" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="19" x="7.62" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="20" x="5.08" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="21" x="2.54" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="22" x="0" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="23" x="-2.54" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="24" x="-5.08" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="25" x="-7.62" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="26" x="-10.16" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="27" x="-12.7" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="28" x="-15.24" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="29" x="-17.78" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<pad name="30" x="-20.32" y="7.62" drill="0.8" shape="offset" rot="R90"/>
<hole x="-22.86" y="7.62" drill="1.778"/>
<hole x="17.78" y="7.62" drill="1.778"/>
<hole x="17.78" y="-7.62" drill="1.778"/>
<wire x1="-24.13" y1="8.89" x2="19.05" y2="8.89" width="0.127" layer="21"/>
<wire x1="19.05" y1="8.89" x2="19.05" y2="-8.89" width="0.127" layer="21"/>
<wire x1="19.05" y1="-8.89" x2="-24.13" y2="-8.89" width="0.127" layer="21"/>
<wire x1="-24.13" y1="-8.89" x2="-24.13" y2="2.54" width="0.127" layer="21"/>
<wire x1="-24.13" y1="2.54" x2="-24.13" y2="8.89" width="0.127" layer="21"/>
<wire x1="-24.13" y1="2.54" x2="-25.4" y2="2.54" width="0.127" layer="21"/>
<wire x1="-25.4" y1="2.54" x2="-25.4" y2="-2.54" width="0.127" layer="21"/>
<wire x1="-19.05" y1="-2.54" x2="-19.05" y2="2.54" width="0.127" layer="21"/>
<wire x1="-19.05" y1="2.54" x2="-24.13" y2="2.54" width="0.127" layer="21"/>
<wire x1="-19.05" y1="-2.54" x2="-25.4" y2="-2.54" width="0.127" layer="21"/>
<text x="-17.78" y="2.54" size="1.27" layer="21" font="vector">&gt;NAME</text>
<text x="-17.78" y="-5.08" size="1.27" layer="21" font="vector">&gt;VALUE</text>
<text x="-20.32" y="-6.35" size="1.016" layer="21" font="vector">1</text>
</package>
</packages>
<symbols>
<symbol name="ARDUINO_BLE33" library_version="26">
<description>&lt;b&gt;Arduino Nano V3.0&lt;/b&gt;&lt;br&gt;&lt;br&gt;

&lt;b&gt;Overview:&lt;/b&gt;&lt;br&gt;

The Arduino Nano is a small, complete, and breadboard-friendly board based on the ATmega328 (Arduino Nano 3.x) or ATmega168 (Arduino Nano 2.x). It has more or less the same functionality of the Arduino Duemilanove, but in a different package. It lacks only a DC power jack, and works with a Mini-B USB cable instead of a standard one.&lt;br&gt;
The Nano was designed and is being produced by Gravitech.&lt;br&gt;&lt;br&gt;

&lt;b&gt;Specifications:&lt;/b&gt;
&lt;table border="1" style="width:auto"&gt;
  &lt;tr&gt;
    &lt;td&gt;Microcontroller&lt;/td&gt;
    &lt;td&gt;Atmel ATmega168 or ATmega328&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Operating Voltage (logic level)&lt;/td&gt;
    &lt;td&gt;5 V&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Input Voltage (recommended)&lt;/td&gt;
    &lt;td&gt;7-12 V&lt;/td&gt;
  &lt;tr&gt;
    &lt;td&gt;Input Voltage (limits)&lt;/td&gt;
    &lt;td&gt;6-20 V&lt;/td&gt;		
  &lt;tr&gt;
    &lt;td&gt;Digital I/O Pins&lt;/td&gt;
    &lt;td&gt;14 (of which 6 provide PWM output)&lt;/td&gt;		
  &lt;tr&gt;
    &lt;td&gt;Analog Input Pins&lt;/td&gt;
    &lt;td&gt;8&lt;/td&gt;
  &lt;tr&gt;
    &lt;td&gt;DC Current per I/O Pin&lt;/td&gt;
    &lt;td&gt;40 mA&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Flash Memory&lt;/td&gt;
    &lt;td&gt;16 KB (ATmega168) or 32 KB (ATmega328) of which 2 KB used by bootloader&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;SRAM&lt;/td&gt;
    &lt;td&gt;1 KB (ATmega168) or 2 KB (ATmega328)&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;EEPROM&lt;/td&gt;
    &lt;td&gt;512 bytes (ATmega168) or 1 KB (ATmega328)&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Clock Speed&lt;/td&gt;
    &lt;td&gt;16 MHz&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Dimensions&lt;/td&gt;
    &lt;td&gt;0.73" x 1.70"&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Length&lt;/td&gt;
    &lt;td&gt;45 mm&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Width&lt;/td&gt;
    &lt;td&gt;18 mm&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Weigth&lt;/td&gt;
    &lt;td&gt;5 g&lt;/td&gt;
  &lt;/tr&gt;
&lt;/table&gt;
&lt;br&gt;&lt;br&gt;

&lt;b&gt;Power:&lt;/b&gt;&lt;br&gt;

The Arduino Nano can be powered via the Mini-B USB connection, 6-20V unregulated external power supply (pin 30), or 5V regulated external power supply (pin 27).&lt;br&gt;
The power source is automatically selected to the highest voltage source.&lt;br&gt;&lt;br&gt;

&lt;b&gt;Memory:&lt;/b&gt;&lt;br&gt;

The ATmega168 has 16 KB of flash memory for storing code (of which 2 KB is used for the bootloader); the ATmega328 has 32 KB, (also with 2 KB used for the bootloader).&lt;br&gt;
The ATmega168 has 1 KB of SRAM and 512 bytes of EEPROM (which can be read and written with the EEPROM library); the ATmega328 has 2 KB of SRAM and 1 KB of EEPROM.&lt;br&gt;&lt;br&gt;

&lt;b&gt;Input and Output:&lt;/b&gt;&lt;br&gt;

Each of the 14 digital pins on the Nano can be used as an input or output, using pinMode(), digitalWrite(), and digitalRead() functions.&lt;br&gt;
They operate at 5 volts.&lt;br&gt;
Each pin can provide or receive a maximum of 40 mA and has an internal pull-up resistor (disconnected by default) of 20-50 kOhms. In addition, some pins have specialized functions.&lt;br&gt;&lt;br&gt;

&lt;a href="https://www.arduino.cc/en/Main/ArduinoBoardNano"&gt;Visit Arduino - ArduinoBoardNano&lt;/a&gt;</description>
<wire x1="-15.24" y1="-29.4" x2="-15" y2="17" width="0.254" layer="94"/>
<wire x1="-15" y1="17" x2="15" y2="17" width="0.254" layer="94"/>
<wire x1="15" y1="17" x2="15.24" y2="-29.4" width="0.254" layer="94"/>
<wire x1="15.24" y1="-29.4" x2="-15.24" y2="-29.4" width="0.254" layer="94"/>
<pin name="TX1" x="-20" y="15" length="middle"/>
<pin name="RX0" x="-20" y="12" length="middle"/>
<pin name="!RESET@1" x="-20" y="9" length="middle" function="dot"/>
<pin name="GND@1" x="-20" y="6" length="middle" direction="sup"/>
<pin name="D2" x="-20" y="3" length="middle"/>
<pin name="D3" x="-20" y="0" length="middle"/>
<pin name="D4" x="-20" y="-3" length="middle"/>
<pin name="D5" x="-20" y="-6" length="middle"/>
<pin name="D6" x="-20" y="-9" length="middle"/>
<pin name="D7" x="-20" y="-12" length="middle"/>
<pin name="D8" x="-20" y="-15" length="middle"/>
<pin name="D9" x="-20" y="-18" length="middle"/>
<pin name="D10" x="-20" y="-21" length="middle"/>
<pin name="D11" x="-20" y="-24" length="middle"/>
<pin name="D12" x="-20" y="-27" length="middle"/>
<pin name="D13" x="20" y="-27" length="middle" rot="R180"/>
<pin name="3V3" x="20" y="-24" length="middle" direction="sup" rot="R180"/>
<pin name="AREF" x="20" y="-21" length="middle" direction="sup" rot="R180"/>
<pin name="A0" x="20" y="-18" length="middle" rot="R180"/>
<pin name="A1" x="20" y="-15" length="middle" rot="R180"/>
<pin name="A2" x="20" y="-12" length="middle" rot="R180"/>
<pin name="A3" x="20" y="-9" length="middle" rot="R180"/>
<pin name="A4/SDA" x="20" y="-6" length="middle" rot="R180"/>
<pin name="A5/SCL" x="20" y="-3" length="middle" rot="R180"/>
<pin name="A6" x="20" y="0" length="middle" rot="R180"/>
<pin name="A7" x="20" y="3" length="middle" rot="R180"/>
<pin name="5V" x="20" y="6" length="middle" direction="sup" rot="R180"/>
<pin name="!RESET@2" x="20" y="9" length="middle" function="dot" rot="R180"/>
<pin name="GND@2" x="20" y="12" length="middle" direction="sup" rot="R180"/>
<pin name="VIN" x="20" y="15" length="middle" direction="sup" rot="R180"/>
<wire x1="3" y1="-22" x2="-3" y2="-22" width="0.254" layer="94"/>
<wire x1="-3" y1="-22" x2="-3" y2="-31" width="0.254" layer="94"/>
<wire x1="-3" y1="-31" x2="3" y2="-31" width="0.254" layer="94"/>
<wire x1="3" y1="-31" x2="3" y2="-22" width="0.254" layer="94"/>
<text x="-15" y="18" size="1.778" layer="95">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="NANO33_BLE" prefix="NANO33_BLE" uservalue="yes" library_version="26">
<description>&lt;b&gt;Arduino Nano V3.0&lt;/b&gt;&lt;br&gt;&lt;br&gt;

&lt;b&gt;Overview:&lt;/b&gt;&lt;br&gt;

&lt;p&gt;The Arduino Nano is a small, complete, and breadboard-friendly board based on the ATmega328 (Arduino Nano 3.x) or ATmega168 (Arduino Nano 2.x). &lt;br&gt;It has more or less the same functionality of the Arduino Duemilanove, but in a different package.&lt;br&gt;
It lacks only a DC power jack, and works with a Mini-B USB cable instead of a standard one.&lt;br&gt;
The Nano was designed and is being produced by Gravitech.&lt;/p&gt;&lt;br&gt;

&lt;b&gt;Specifications:&lt;/b&gt;
&lt;table border="1" style="width:auto"&gt;
  &lt;tr&gt;
    &lt;td&gt;Microcontroller&lt;/td&gt;
    &lt;td&gt;Atmel ATmega168 or ATmega328&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Operating Voltage (logic level)&lt;/td&gt;
    &lt;td&gt;5 V&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Input Voltage (recommended)&lt;/td&gt;
    &lt;td&gt;7-12 V&lt;/td&gt;
  &lt;tr&gt;
    &lt;td&gt;Input Voltage (limits)&lt;/td&gt;
    &lt;td&gt;6-20 V&lt;/td&gt;		
  &lt;tr&gt;
    &lt;td&gt;Digital I/O Pins&lt;/td&gt;
    &lt;td&gt;14 (of which 6 provide PWM output)&lt;/td&gt;		
  &lt;tr&gt;
    &lt;td&gt;Analog Input Pins&lt;/td&gt;
    &lt;td&gt;8&lt;/td&gt;
  &lt;tr&gt;
    &lt;td&gt;DC Current per I/O Pin&lt;/td&gt;
    &lt;td&gt;40 mA&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Flash Memory&lt;/td&gt;
    &lt;td&gt;16 KB (ATmega168) or 32 KB (ATmega328) of which 2 KB used by bootloader&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;SRAM&lt;/td&gt;
    &lt;td&gt;1 KB (ATmega168) or 2 KB (ATmega328)&lt;/td&gt;		
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;EEPROM&lt;/td&gt;
    &lt;td&gt;512 bytes (ATmega168) or 1 KB (ATmega328)&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Clock Speed&lt;/td&gt;
    &lt;td&gt;16 MHz&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Dimensions&lt;/td&gt;
    &lt;td&gt;0.73" x 1.70"&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Length&lt;/td&gt;
    &lt;td&gt;45 mm&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Width&lt;/td&gt;
    &lt;td&gt;18 mm&lt;/td&gt;
  &lt;/tr&gt;
  &lt;tr&gt;
    &lt;td&gt;Weigth&lt;/td&gt;
    &lt;td&gt;5 g&lt;/td&gt;
  &lt;/tr&gt;
&lt;/table&gt;
&lt;br&gt;&lt;br&gt;

&lt;b&gt;Power:&lt;/b&gt;&lt;br&gt;

&lt;p&gt;The Arduino Nano can be powered via the Mini-B USB connection, 6-20V unregulated external power supply (pin 30), or 5V regulated external power supply (pin 27).&lt;br&gt;
The power source is automatically selected to the highest voltage source.&lt;/p&gt;&lt;br&gt;

&lt;b&gt;Memory:&lt;/b&gt;&lt;br&gt;

&lt;p&gt;The ATmega168 has 16 KB of flash memory for storing code (of which 2 KB is used for the bootloader); the ATmega328 has 32 KB, (also with 2 KB used for the bootloader).&lt;br&gt;
The ATmega168 has 1 KB of SRAM and 512 bytes of EEPROM (which can be read and written with the EEPROM library); the ATmega328 has 2 KB of SRAM and 1 KB of EEPROM.&lt;/p&gt;&lt;br&gt;

&lt;b&gt;Input and Output:&lt;/b&gt;&lt;br&gt;

&lt;p&gt;Each of the 14 digital pins on the Nano can be used as an input or output, using pinMode(), digitalWrite(), and digitalRead() functions.&lt;br&gt;
They operate at 5 volts.&lt;br&gt;
Each pin can provide or receive a maximum of 40 mA and has an internal pull-up resistor (disconnected by default) of 20-50 kOhms. In addition, some pins have specialized functions.&lt;/p&gt;&lt;br&gt;

&lt;a href="https://www.arduino.cc/en/Main/ArduinoBoardNano"&gt;Visit Arduino - ArduinoBoardNano&lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="ARDUINO_BLE33" x="0" y="0"/>
</gates>
<devices>
<device name="SMT" package="NANO_BLE33_SMT">
<connects>
<connect gate="G$1" pin="!RESET@1" pad="18"/>
<connect gate="G$1" pin="!RESET@2" pad="13"/>
<connect gate="G$1" pin="3V3" pad="2"/>
<connect gate="G$1" pin="5V" pad="12"/>
<connect gate="G$1" pin="A0" pad="4"/>
<connect gate="G$1" pin="A1" pad="5"/>
<connect gate="G$1" pin="A2" pad="6"/>
<connect gate="G$1" pin="A3" pad="7"/>
<connect gate="G$1" pin="A4/SDA" pad="8"/>
<connect gate="G$1" pin="A5/SCL" pad="9"/>
<connect gate="G$1" pin="A6" pad="10"/>
<connect gate="G$1" pin="A7" pad="11"/>
<connect gate="G$1" pin="AREF" pad="3"/>
<connect gate="G$1" pin="D10" pad="28"/>
<connect gate="G$1" pin="D11" pad="29"/>
<connect gate="G$1" pin="D12" pad="30"/>
<connect gate="G$1" pin="D13" pad="1"/>
<connect gate="G$1" pin="D2" pad="20"/>
<connect gate="G$1" pin="D3" pad="21"/>
<connect gate="G$1" pin="D4" pad="22"/>
<connect gate="G$1" pin="D5" pad="23"/>
<connect gate="G$1" pin="D6" pad="24"/>
<connect gate="G$1" pin="D7" pad="25"/>
<connect gate="G$1" pin="D8" pad="26"/>
<connect gate="G$1" pin="D9" pad="27"/>
<connect gate="G$1" pin="GND@1" pad="19"/>
<connect gate="G$1" pin="GND@2" pad="14"/>
<connect gate="G$1" pin="RX0" pad="17"/>
<connect gate="G$1" pin="TX1" pad="16"/>
<connect gate="G$1" pin="VIN" pad="15"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="PIN" package="NANO_BLE33_PIN">
<connects>
<connect gate="G$1" pin="!RESET@1" pad="18"/>
<connect gate="G$1" pin="!RESET@2" pad="13"/>
<connect gate="G$1" pin="3V3" pad="2"/>
<connect gate="G$1" pin="5V" pad="12"/>
<connect gate="G$1" pin="A0" pad="4"/>
<connect gate="G$1" pin="A1" pad="5"/>
<connect gate="G$1" pin="A2" pad="6"/>
<connect gate="G$1" pin="A3" pad="7"/>
<connect gate="G$1" pin="A4/SDA" pad="8"/>
<connect gate="G$1" pin="A5/SCL" pad="9"/>
<connect gate="G$1" pin="A6" pad="10"/>
<connect gate="G$1" pin="A7" pad="11"/>
<connect gate="G$1" pin="AREF" pad="3"/>
<connect gate="G$1" pin="D10" pad="28"/>
<connect gate="G$1" pin="D11" pad="29"/>
<connect gate="G$1" pin="D12" pad="30"/>
<connect gate="G$1" pin="D13" pad="1"/>
<connect gate="G$1" pin="D2" pad="20"/>
<connect gate="G$1" pin="D3" pad="21"/>
<connect gate="G$1" pin="D4" pad="22"/>
<connect gate="G$1" pin="D5" pad="23"/>
<connect gate="G$1" pin="D6" pad="24"/>
<connect gate="G$1" pin="D7" pad="25"/>
<connect gate="G$1" pin="D8" pad="26"/>
<connect gate="G$1" pin="D9" pad="27"/>
<connect gate="G$1" pin="GND@1" pad="19"/>
<connect gate="G$1" pin="GND@2" pad="14"/>
<connect gate="G$1" pin="RX0" pad="17"/>
<connect gate="G$1" pin="TX1" pad="16"/>
<connect gate="G$1" pin="VIN" pad="15"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Power_Symbols" urn="urn:adsk.wipprod:fs.file:vf.w1fxe-0uTo-qhfptjUaJ6Q">
<description>&lt;B&gt;Supply &amp; Ground symbols</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:16502380/3" locally_modified="yes" library_version="5">
<description>Ground (GND) Arrow</description>
<wire x1="-1.27" y1="-2.6" x2="1.27" y2="-2.6" width="0.1524" layer="94"/>
<wire x1="1.27" y1="-2.6" x2="0" y2="-3.87" width="0.1524" layer="94"/>
<wire x1="0" y1="-3.87" x2="-1.27" y2="-2.6" width="0.1524" layer="94"/>
<pin name="VCC" x="0" y="0" visible="off" length="short" direction="sup" rot="R270"/>
<text x="0" y="-4.52" size="1.778" layer="96" align="top-center">&gt;VALUE</text>
</symbol>
<symbol name="VCC-ARROW" urn="urn:adsk.eagle:symbol:18498256/2" locally_modified="yes" library_version="7">
<description>Voltage Arrow</description>
<pin name="VCC" x="0" y="0" visible="off" length="short" direction="sup" rot="R90"/>
<text x="0" y="3.22" size="1.778" layer="96" rot="R180" align="top-center">&gt;VALUE</text>
<wire x1="1.27" y1="0.595" x2="0" y2="2.5" width="0.254" layer="94"/>
<wire x1="0" y1="2.5" x2="-1.27" y2="0.595" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:16502425/6" prefix="SUPPLY" uservalue="yes" library_version="7">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt; - Ground (GND) Arrow</description>
<gates>
<gate name="G$1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name="">
<attribute name="CATEGORY" value="Supply" constant="no"/>
<attribute name="VALUE" value="GND" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="5V" urn="urn:adsk.eagle:component:16502432/8" locally_modified="yes" prefix="SUPPLY" uservalue="yes" library_version="7">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;  5 Volt (5V) Bar</description>
<gates>
<gate name="G$1" symbol="VCC-ARROW" x="0" y="0" addlevel="request"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name="">
<attribute name="CATEGORY" value="Supply" constant="no"/>
<attribute name="VALUE" value="5V" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Frames" urn="urn:adsk.wipprod:fs.file:vf.-WXByK6ERsqEjTKva-ibYA">
<description>Frames for Sheet and Layout</description>
<packages>
</packages>
<symbols>
<symbol name="A4L-LOC" urn="urn:adsk.eagle:symbol:49224739/1" library_version="8" library_locally_modified="yes">
<frame x1="-297" y1="0" x2="0" y2="210" columns="6" rows="4" layer="94"/>
</symbol>
<symbol name="DOCFIELD" urn="urn:adsk.eagle:symbol:49224729/1" locally_modified="yes" library_version="8" library_locally_modified="yes">
<wire x1="-50" y1="5" x2="-50" y2="0" width="0.1016" layer="94"/>
<wire x1="-100" y1="10" x2="0" y2="10" width="0.1016" layer="94"/>
<wire x1="-100" y1="15" x2="-100" y2="10" width="0.1016" layer="94"/>
<wire x1="-100" y1="10" x2="-100" y2="5" width="0.1016" layer="94"/>
<wire x1="-100" y1="5" x2="-100" y2="0" width="0.1016" layer="94"/>
<wire x1="-100" y1="0" x2="-50" y2="0" width="0.1016" layer="94"/>
<wire x1="-50" y1="0" x2="0" y2="0" width="0.1016" layer="94"/>
<wire x1="-100" y1="15" x2="0" y2="15" width="0.1016" layer="94"/>
<wire x1="0" y1="15" x2="0" y2="10" width="0.1016" layer="94"/>
<wire x1="0" y1="10" x2="0" y2="5" width="0.1016" layer="94"/>
<wire x1="0" y1="5" x2="0" y2="0" width="0.1016" layer="94"/>
<wire x1="-100" y1="5" x2="0" y2="5" width="0.1016" layer="94"/>
<wire x1="-100" y1="15" x2="-100" y2="20" width="0.1016" layer="94"/>
<wire x1="-100" y1="20" x2="0" y2="20" width="0.1016" layer="94"/>
<wire x1="0" y1="20" x2="0" y2="15" width="0.1016" layer="94"/>
<wire x1="0" y1="20" x2="0" y2="30" width="0.1016" layer="94"/>
<wire x1="0" y1="30" x2="-100" y2="30" width="0.1016" layer="94"/>
<wire x1="-100" y1="30" x2="-100" y2="20" width="0.1016" layer="94"/>
<wire x1="0" y1="25" x2="-100" y2="25" width="0.1016" layer="94"/>
<text x="-99" y="1" size="3" layer="94">Date:</text>
<text x="-88" y="1" size="3" layer="94">&gt;LAST_DATE_TIME</text>
<text x="-49" y="1" size="3" layer="94">Sheet:</text>
<text x="-36" y="1" size="3" layer="94">&gt;SHEET_TOTAL</text>
<text x="-99" y="11" size="3" layer="94">PROJECT:</text>
<text x="-99" y="6" size="3" layer="94">Document:</text>
<text x="-78" y="11" size="3" layer="94">&gt;PROJECT_NAME</text>
<text x="-78" y="6" size="3" layer="94">&gt;SHEET_HEADLINE</text>
<text x="-50" y="26" size="3" layer="94" align="bottom-center">&gt;COMPANY</text>
<text x="-99" y="16" size="3" layer="94">License:</text>
<text x="-99" y="21" size="3" layer="94">&gt;COPYRIGHT</text>
<text x="-83" y="16" size="3" layer="94">&gt;LICENSE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="A4L-LOC" urn="urn:adsk.eagle:component:49224750/2" locally_modified="yes" prefix="FRAME" uservalue="yes" library_version="8" library_locally_modified="yes">
<description>DIN A4 FRAME landscape with location and doc. field</description>
<gates>
<gate name="G$1" symbol="A4L-LOC" x="0" y="0" addlevel="always"/>
<gate name="G$2" symbol="DOCFIELD" x="-3.8" y="3.8" addlevel="always"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
<attribute name="COMPANY" value="https://github.com/atari-researchlab/cicerone-airlink"/>
<attribute name="COPYRIGHT" value="Copyright (C) 2025 ATARI Research Lab"/>
<attribute name="LICENSE" value="CERN-OHL-S-2.0+"/>
<attribute name="PROJECT_NAME" value="CICERONE Airlink"/>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="1" drill="0">
</class>
<class number="1" name="PWR" width="1.5" drill="0">
</class>
<class number="2" name="GND" width="1" drill="0">
</class>
</classes>
<parts>
<part name="LIPO_RIDER" library="Custom Cicerone" library_urn="urn:adsk.wipprod:fs.file:vf.15uM3mRNSnC6RDIQiURjTA" deviceset="LIPO-RIDER" device=""/>
<part name="NB_IOT" library="Custom Cicerone" library_urn="urn:adsk.wipprod:fs.file:vf.15uM3mRNSnC6RDIQiURjTA" deviceset="GROVE-UART" device="SMD"/>
<part name="RTC" library="Custom Cicerone" library_urn="urn:adsk.wipprod:fs.file:vf.15uM3mRNSnC6RDIQiURjTA" deviceset="RTC-DS3231M" device="MOD-90" value="MODULO_RTC"/>
<part name="T6793-5K" library="Custom Cicerone" library_urn="urn:adsk.wipprod:fs.file:vf.15uM3mRNSnC6RDIQiURjTA" deviceset="T6793" device=""/>
<part name="SEN5X" library="Custom Cicerone" library_urn="urn:adsk.wipprod:fs.file:vf.15uM3mRNSnC6RDIQiURjTA" deviceset="I2C-HEADER" device=""/>
<part name="CURR_MEAS" library="Custom Cicerone" library_urn="urn:adsk.wipprod:fs.file:vf.15uM3mRNSnC6RDIQiURjTA" deviceset="CURR-MEAS" device="" value="I→"/>
<part name="POWER_SWITCH" library="Custom Cicerone" library_urn="urn:adsk.wipprod:fs.file:vf.15uM3mRNSnC6RDIQiURjTA" deviceset="USB_SWITCH" device=""/>
<part name="TPBAT" library="testpad" library_urn="urn:adsk.wipprod:fs.file:vf.3lHXDImfT4KV5U3V6H2GRQ" deviceset="PTR1" device="TP20SQ" package3d_urn="urn:adsk.eagle:package:27980/1"/>
<part name="TPVIN" library="testpad" library_urn="urn:adsk.wipprod:fs.file:vf.3lHXDImfT4KV5U3V6H2GRQ" deviceset="PTR1" device="TP20SQ" package3d_urn="urn:adsk.eagle:package:27980/1"/>
<part name="TP5V" library="testpad" library_urn="urn:adsk.wipprod:fs.file:vf.3lHXDImfT4KV5U3V6H2GRQ" deviceset="PTR1" device="TP20SQ" package3d_urn="urn:adsk.eagle:package:27980/1"/>
<part name="TPSDA" library="testpad" library_urn="urn:adsk.wipprod:fs.file:vf.3lHXDImfT4KV5U3V6H2GRQ" deviceset="PTR1" device="TP20SQ" package3d_urn="urn:adsk.eagle:package:27980/1"/>
<part name="TPSCL" library="testpad" library_urn="urn:adsk.wipprod:fs.file:vf.3lHXDImfT4KV5U3V6H2GRQ" deviceset="PTR1" device="TP20SQ" package3d_urn="urn:adsk.eagle:package:27980/1"/>
<part uuid="2882400017" name="TPTX" library="testpad" library_urn="urn:adsk.wipprod:fs.file:vf.3lHXDImfT4KV5U3V6H2GRQ" deviceset="PTR1" device="TP20SQ" package3d_urn="urn:adsk.eagle:package:27980/1"/>
<part name="TPRX" library="testpad" library_urn="urn:adsk.wipprod:fs.file:vf.3lHXDImfT4KV5U3V6H2GRQ" deviceset="PTR1" device="TP20SQ" package3d_urn="urn:adsk.eagle:package:27980/1"/>
<part name="NANO33_BLE" library="ArduinoNano" library_urn="urn:adsk.wipprod:fs.file:vf.yiiWTITUTr2LdZfMQMe1SA" deviceset="NANO33_BLE" device="PIN" value="NANO33_BLEPIN"/>
<part name="SUPPLY1" library="Power_Symbols" library_urn="urn:adsk.wipprod:fs.file:vf.w1fxe-0uTo-qhfptjUaJ6Q" deviceset="GND" device="" value="GND"/>
<part name="SUPPLY2" library="Power_Symbols" library_urn="urn:adsk.wipprod:fs.file:vf.w1fxe-0uTo-qhfptjUaJ6Q" deviceset="GND" device="" value="GND"/>
<part name="SUPPLY3" library="Power_Symbols" library_urn="urn:adsk.wipprod:fs.file:vf.w1fxe-0uTo-qhfptjUaJ6Q" deviceset="GND" device="" value="GND"/>
<part name="SUPPLY4" library="Power_Symbols" library_urn="urn:adsk.wipprod:fs.file:vf.w1fxe-0uTo-qhfptjUaJ6Q" deviceset="5V" device="" value="5V"/>
<part name="SUPPLY5" library="Power_Symbols" library_urn="urn:adsk.wipprod:fs.file:vf.w1fxe-0uTo-qhfptjUaJ6Q" deviceset="5V" device="" value="5V"/>
<part name="SUPPLY6" library="Power_Symbols" library_urn="urn:adsk.wipprod:fs.file:vf.w1fxe-0uTo-qhfptjUaJ6Q" deviceset="5V" device="" value="5V"/>
<part name="SUPPLY7" library="Power_Symbols" library_urn="urn:adsk.wipprod:fs.file:vf.w1fxe-0uTo-qhfptjUaJ6Q" deviceset="5V" device="" value="5V"/>
<part name="FRAME1" library="Frames" library_urn="urn:adsk.wipprod:fs.file:vf.-WXByK6ERsqEjTKva-ibYA" deviceset="A4L-LOC" device=""/>
</parts>
<sheets>
<sheet>
<description>Custom PCB</description>
<plain>
<text x="20" y="138" size="3.81" layer="94">Power management</text>
<text x="166" y="138" size="3.81" layer="94">Microcontroller and sensors</text>
<text x="1" y="0" size="2.1844" layer="94" font="fixed"> ------------------------------------------------------------------------------
| Copyright (C) 2025 ATARI Research Lab                                        |
| This source describes Open Hardware and is licensed under CERN-OHL-S-2.0+.   |
| You may modify and redistribute this source under the terms of the CERN Open |
| Hardware Licence, strongly-reciprocal variant, version 2.0 or any later      |
| version. See https://cern-ohl.web.cern.ch for details.                       |
| This source is distributed WITHOUT ANY EXPRESS OR IMPLIED WARRANTY,          |
| INCLUDING OF MERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A         |
| PARTICULAR PURPOSE. Please see the licence text for applicable conditions.   |
|                                                                              |
| Source location: https://github.com/atari-researchlab/cicerone-airlink       |
| As per CERN-OHL-S-2.0 section 4, should you produce hardware based on these  |
| sources, you must maintain the source location visible on the silk screen or |
| top copper.                                                                  |
 ------------------------------------------------------------------------------</text>
</plain>
<instances>
<instance part="LIPO_RIDER" gate="G$1" x="33" y="76" smashed="yes" rot="MR0">
<attribute name="NAME" x="33" y="75" size="1.27" layer="95" rot="R180"/>
</instance>
<instance part="NB_IOT" gate="G$1" x="245" y="84" smashed="yes">
<attribute name="NAME" x="246" y="98" size="1.778" layer="95"/>
</instance>
<instance part="RTC" gate="G$1" x="148" y="89" smashed="yes" rot="MR0">
<attribute name="NAME" x="147" y="103" size="1.778" layer="95" rot="MR0"/>
</instance>
<instance part="T6793-5K" gate="G$1" x="148" y="108" smashed="yes" rot="MR0">
<attribute name="NAME" x="147" y="128" size="1.778" layer="95" rot="MR0"/>
</instance>
<instance part="SEN5X" gate="G$1" x="148" y="70" smashed="yes" rot="MR0">
<attribute name="NAME" x="147" y="84" size="1.778" layer="95" rot="MR0"/>
</instance>
<instance part="CURR_MEAS" gate="G$1" x="45" y="99" smashed="yes">
<attribute name="NAME" x="45" y="107" size="1.27" layer="95"/>
</instance>
<instance part="POWER_SWITCH" gate="G$1" x="54" y="86" smashed="yes" rot="MR180">
<attribute name="NAME" x="54" y="87" size="1.27" layer="95"/>
</instance>
<instance part="TPBAT" gate="G$1" x="58" y="93" smashed="yes" rot="R90">
<attribute name="NAME" x="64.95" y="93.016" size="1.778" layer="95" align="center-left"/>
<attribute name="TP_SIGNAL_NAME" x="60.54" y="94.27" size="1.778" layer="97" rot="R90"/>
</instance>
<instance part="TPVIN" gate="G$1" x="58" y="90" smashed="yes" rot="R90">
<attribute name="NAME" x="64.95" y="90.016" size="1.778" layer="95" align="center-left"/>
<attribute name="TP_SIGNAL_NAME" x="60.54" y="91.27" size="1.778" layer="97" rot="R90"/>
</instance>
<instance part="TP5V" gate="G$1" x="58" y="96" smashed="yes" rot="R90">
<attribute name="NAME" x="65.35" y="95.984" size="1.778" layer="95" align="center-left"/>
<attribute name="TP_SIGNAL_NAME" x="60.54" y="97.27" size="1.778" layer="97" rot="R90"/>
</instance>
<instance part="TPSDA" gate="G$1" x="169" y="125" smashed="yes" rot="R90">
<attribute name="NAME" x="175.65" y="125.016" size="1.778" layer="95" align="center-left"/>
<attribute name="TP_SIGNAL_NAME" x="171.54" y="126.27" size="1.778" layer="97" rot="R90"/>
</instance>
<instance part="TPSCL" gate="G$1" x="169" y="122" smashed="yes" rot="R90">
<attribute name="NAME" x="175.65" y="122.016" size="1.778" layer="95" align="center-left"/>
<attribute name="TP_SIGNAL_NAME" x="171.54" y="123.27" size="1.778" layer="97" rot="R90"/>
</instance>
<instance part="TPTX" gate="G$1" x="245" y="81" smashed="yes" rot="R90">
<attribute name="NAME" x="252.35" y="80.984" size="1.778" layer="95" align="center-left"/>
<attribute name="TP_SIGNAL_NAME" x="247.54" y="82.27" size="1.778" layer="97" rot="R90"/>
</instance>
<instance part="TPRX" gate="G$1" x="245" y="78" smashed="yes" rot="R90">
<attribute name="NAME" x="252.35" y="77.984" size="1.778" layer="95" align="center-left"/>
<attribute name="TP_SIGNAL_NAME" x="247.54" y="79.27" size="1.778" layer="97" rot="R90"/>
</instance>
<instance part="NANO33_BLE" gate="G$1" x="209" y="98" smashed="yes" rot="R180">
<attribute name="NAME" x="224" y="130" size="1.778" layer="95" rot="MR0"/>
</instance>
<instance part="SUPPLY1" gate="G$1" x="44" y="76" smashed="yes">
<attribute name="VALUE" x="44" y="71.48" size="1.778" layer="96" align="top-center"/>
</instance>
<instance part="SUPPLY2" gate="G$1" x="155" y="66" smashed="yes">
<attribute name="VALUE" x="155" y="61.48" size="1.778" layer="96" align="top-center"/>
</instance>
<instance part="SUPPLY3" gate="G$1" x="211" y="77" smashed="yes">
<attribute name="VALUE" x="211" y="72.48" size="1.778" layer="96" align="top-center"/>
</instance>
<instance part="SUPPLY4" gate="G$1" x="40" y="108" smashed="yes">
<attribute name="VALUE" x="40" y="111.22" size="1.778" layer="96" rot="R180" align="top-center"/>
</instance>
<instance part="SUPPLY5" gate="G$1" x="181" y="92" smashed="yes">
<attribute name="VALUE" x="181" y="95.22" size="1.778" layer="96" rot="R180" align="top-center"/>
</instance>
<instance part="SUPPLY6" gate="G$1" x="158" y="127" smashed="yes">
<attribute name="VALUE" x="158" y="130.22" size="1.778" layer="96" rot="R180" align="top-center"/>
</instance>
<instance part="SUPPLY7" gate="G$1" x="238" y="100" smashed="yes">
<attribute name="VALUE" x="238" y="103.22" size="1.778" layer="96" rot="R180" align="top-center"/>
</instance>
<instance part="FRAME1" gate="G$1" x="294" y="-4" smashed="yes"/>
<instance part="FRAME1" gate="G$2" x="290.2" y="-0.2" smashed="yes">
<attribute name="LAST_DATE_TIME" x="202.2" y="0.8" size="3" layer="94"/>
<attribute name="SHEET_TOTAL" x="254.2" y="0.8" size="3" layer="94"/>
<attribute name="PROJECT_NAME" x="212.2" y="10.8" size="3" layer="94"/>
<attribute name="SHEET_HEADLINE" x="212.2" y="5.8" size="3" layer="94"/>
<attribute name="COMPANY" x="240.2" y="25.8" size="3" layer="94" align="bottom-center"/>
<attribute name="COPYRIGHT" x="191.2" y="20.8" size="3" layer="94"/>
<attribute name="LICENSE" x="207.2" y="15.8" size="3" layer="94"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="SDA" class="0">
<segment>
<wire x1="153" y1="72" x2="164" y2="72" width="0.1524" layer="91"/>
<wire x1="164" y1="72" x2="164" y2="91" width="0.1524" layer="91"/>
<wire x1="153" y1="91" x2="164" y2="91" width="0.1524" layer="91"/>
<wire x1="164" y1="91" x2="164" y2="104" width="0.1524" layer="91"/>
<wire x1="164" y1="104" x2="164" y2="125" width="0.1524" layer="91"/>
<wire x1="164" y1="125" x2="153" y2="125" width="0.1524" layer="91"/>
<pinref part="TPSDA" gate="G$1" pin="TP"/>
<wire x1="166.46" y1="125" x2="164" y2="125" width="0.1524" layer="91"/>
<wire x1="189" y1="104" x2="164" y2="104" width="0.1524" layer="91"/>
<junction x="164" y="91"/>
<junction x="164" y="104"/>
<junction x="164" y="125"/>
<pinref part="NANO33_BLE" gate="G$1" pin="A4/SDA"/>
<pinref part="RTC" gate="G$1" pin="SDA"/>
<pinref part="T6793-5K" gate="G$1" pin="SDA"/>
<pinref part="SEN5X" gate="G$1" pin="SDA"/>
</segment>
</net>
<net name="EN" class="0">
<segment>
<wire x1="49" y1="84" x2="46" y2="84" width="0.1524" layer="91"/>
<wire x1="46" y1="84" x2="46" y2="87" width="0.1524" layer="91"/>
<wire x1="46" y1="87" x2="38" y2="87" width="0.1524" layer="91"/>
<pinref part="LIPO_RIDER" gate="G$1" pin="EN"/>
<pinref part="POWER_SWITCH" gate="G$1" pin="EN"/>
</segment>
</net>
<net name="5V" class="1">
<segment>
<pinref part="SUPPLY4" gate="G$1" pin="VCC"/>
<wire x1="40" y1="108" x2="40" y2="104" width="0.1524" layer="91"/>
<wire x1="40" y1="104" x2="40" y2="101" width="0.1524" layer="91"/>
<wire x1="38" y1="84" x2="40" y2="84" width="0.1524" layer="91"/>
<wire x1="40" y1="101" x2="40" y2="96" width="0.1524" layer="91"/>
<pinref part="TP5V" gate="G$1" pin="TP"/>
<wire x1="40" y1="96" x2="40" y2="84" width="0.1524" layer="91"/>
<wire x1="55.46" y1="96" x2="40" y2="96" width="0.1524" layer="91"/>
<junction x="40" y="104"/>
<junction x="40" y="101"/>
<junction x="40" y="96"/>
<pinref part="LIPO_RIDER" gate="G$1" pin="5V"/>
<pinref part="CURR_MEAS" gate="G$1" pin="5VOUT"/>
<pinref part="CURR_MEAS" gate="G$1" pin="5VIN"/>
</segment>
<segment>
<wire x1="153" y1="81" x2="158" y2="81" width="0.1524" layer="91"/>
<wire x1="153" y1="100" x2="158" y2="100" width="0.1524" layer="91"/>
<wire x1="153" y1="113" x2="158" y2="113" width="0.1524" layer="91"/>
<pinref part="SUPPLY6" gate="G$1" pin="VCC"/>
<wire x1="158" y1="127" x2="158" y2="113" width="0.1524" layer="91"/>
<junction x="158" y="113"/>
<wire x1="158" y1="113" x2="158" y2="100" width="0.1524" layer="91"/>
<junction x="158" y="100"/>
<wire x1="158" y1="100" x2="158" y2="81" width="0.1524" layer="91"/>
<pinref part="RTC" gate="G$1" pin="VCC"/>
<pinref part="T6793-5K" gate="G$1" pin="VCC"/>
<pinref part="SEN5X" gate="G$1" pin="VCC"/>
</segment>
<segment>
<pinref part="SUPPLY5" gate="G$1" pin="VCC"/>
<wire x1="181" y1="92" x2="181" y2="83" width="0.1524" layer="91"/>
<wire x1="181" y1="83" x2="189" y2="83" width="0.1524" layer="91"/>
<pinref part="NANO33_BLE" gate="G$1" pin="VIN"/>
</segment>
<segment>
<pinref part="SUPPLY7" gate="G$1" pin="VCC"/>
<wire x1="240" y1="95" x2="238" y2="95" width="0.1524" layer="91"/>
<wire x1="238" y1="95" x2="238" y2="100" width="0.1524" layer="91"/>
<pinref part="NB_IOT" gate="G$1" pin="5V"/>
</segment>
</net>
<net name="GND" class="2">
<segment>
<pinref part="SUPPLY1" gate="G$1" pin="VCC"/>
<wire x1="44" y1="76" x2="44" y2="78" width="0.1524" layer="91"/>
<wire x1="44" y1="78" x2="38" y2="78" width="0.1524" layer="91"/>
<wire x1="49" y1="78" x2="44" y2="78" width="0.1524" layer="91"/>
<junction x="44" y="78"/>
<pinref part="LIPO_RIDER" gate="G$1" pin="GND"/>
<pinref part="POWER_SWITCH" gate="G$1" pin="GND"/>
</segment>
<segment>
<pinref part="SUPPLY2" gate="G$1" pin="VCC"/>
<wire x1="153" y1="78" x2="155" y2="78" width="0.1524" layer="91"/>
<wire x1="155" y1="78" x2="155" y2="66" width="0.1524" layer="91"/>
<junction x="155" y="78"/>
<wire x1="153" y1="97" x2="155" y2="97" width="0.1524" layer="91"/>
<wire x1="155" y1="97" x2="155" y2="78" width="0.1524" layer="91"/>
<junction x="155" y="97"/>
<wire x1="153" y1="110" x2="155" y2="110" width="0.1524" layer="91"/>
<wire x1="155" y1="110" x2="155" y2="97" width="0.1524" layer="91"/>
<junction x="155" y="110"/>
<wire x1="153" y1="119" x2="155" y2="119" width="0.1524" layer="91"/>
<wire x1="155" y1="119" x2="155" y2="110" width="0.1524" layer="91"/>
<pinref part="RTC" gate="G$1" pin="GND"/>
<pinref part="T6793-5K" gate="G$1" pin="GND"/>
<pinref part="T6793-5K" gate="G$1" pin="SEL"/>
<pinref part="SEN5X" gate="G$1" pin="GND"/>
</segment>
<segment>
<pinref part="SUPPLY3" gate="G$1" pin="VCC"/>
<wire x1="211" y1="77" x2="211" y2="79" width="0.1524" layer="91"/>
<wire x1="189" y1="86" x2="187" y2="86" width="0.1524" layer="91"/>
<wire x1="187" y1="86" x2="187" y2="79" width="0.1524" layer="91"/>
<wire x1="231" y1="92" x2="231" y2="79" width="0.1524" layer="91"/>
<wire x1="231" y1="79" x2="211" y2="79" width="0.1524" layer="91"/>
<wire x1="211" y1="79" x2="187" y2="79" width="0.1524" layer="91"/>
<wire x1="229" y1="92" x2="231" y2="92" width="0.1524" layer="91"/>
<wire x1="240" y1="92" x2="231" y2="92" width="0.1524" layer="91"/>
<junction x="211" y="79"/>
<junction x="231" y="92"/>
<pinref part="NANO33_BLE" gate="G$1" pin="GND@1"/>
<pinref part="NANO33_BLE" gate="G$1" pin="GND@2"/>
<pinref part="NB_IOT" gate="G$1" pin="GND"/>
</segment>
</net>
<net name="TX_ARDU" class="0">
<segment>
<wire x1="237" y1="83" x2="229" y2="83" width="0.1524" layer="91"/>
<wire x1="240" y1="89" x2="237" y2="89" width="0.1524" layer="91"/>
<wire x1="237" y1="89" x2="237" y2="83" width="0.1524" layer="91"/>
<wire x1="237" y1="83" x2="237" y2="81" width="0.1524" layer="91"/>
<pinref part="TPTX" gate="G$1" pin="TP"/>
<wire x1="242.46" y1="81" x2="237" y2="81" width="0.1524" layer="91"/>
<junction x="237" y="83"/>
<pinref part="NANO33_BLE" gate="G$1" pin="TX1"/>
<pinref part="NB_IOT" gate="G$1" pin="RX"/>
</segment>
</net>
<net name="SCL" class="0">
<segment>
<wire x1="153" y1="122" x2="161" y2="122" width="0.1524" layer="91"/>
<wire x1="161" y1="122" x2="161" y2="101" width="0.1524" layer="91"/>
<wire x1="161" y1="101" x2="161" y2="94" width="0.1524" layer="91"/>
<wire x1="161" y1="94" x2="153" y2="94" width="0.1524" layer="91"/>
<wire x1="153" y1="75" x2="161" y2="75" width="0.1524" layer="91"/>
<wire x1="161" y1="75" x2="161" y2="94" width="0.1524" layer="91"/>
<pinref part="TPSCL" gate="G$1" pin="TP"/>
<wire x1="166.46" y1="122" x2="161" y2="122" width="0.1524" layer="91"/>
<wire x1="161" y1="101" x2="189" y2="101" width="0.1524" layer="91"/>
<junction x="161" y="122"/>
<junction x="161" y="101"/>
<junction x="161" y="94"/>
<pinref part="NANO33_BLE" gate="G$1" pin="A5/SCL"/>
<pinref part="RTC" gate="G$1" pin="SCL"/>
<pinref part="T6793-5K" gate="G$1" pin="SCL"/>
<pinref part="SEN5X" gate="G$1" pin="SCL"/>
</segment>
</net>
<net name="RX_ARDU" class="0">
<segment>
<wire x1="229" y1="86" x2="234" y2="86" width="0.1524" layer="91"/>
<wire x1="234" y1="86" x2="240" y2="86" width="0.1524" layer="91"/>
<pinref part="TPRX" gate="G$1" pin="TP"/>
<wire x1="242.46" y1="78" x2="234" y2="78" width="0.1524" layer="91"/>
<wire x1="234" y1="78" x2="234" y2="86" width="0.1524" layer="91"/>
<junction x="234" y="86"/>
<pinref part="NANO33_BLE" gate="G$1" pin="RX0"/>
<pinref part="NB_IOT" gate="G$1" pin="TX"/>
</segment>
</net>
<net name="VBAT" class="0">
<segment>
<wire x1="38" y1="93" x2="55.46" y2="93" width="0.1524" layer="91"/>
<pinref part="TPBAT" gate="G$1" pin="TP"/>
<pinref part="LIPO_RIDER" gate="G$1" pin="BAT"/>
</segment>
</net>
<net name="VUSB" class="1">
<segment>
<wire x1="49" y1="81" x2="43" y2="81" width="0.1524" layer="91"/>
<pinref part="TPVIN" gate="G$1" pin="TP"/>
<wire x1="55.46" y1="90" x2="43" y2="90" width="0.1524" layer="91"/>
<wire x1="43" y1="90" x2="38" y2="90" width="0.1524" layer="91"/>
<wire x1="43" y1="90" x2="43" y2="81" width="0.1524" layer="91"/>
<junction x="43" y="90"/>
<pinref part="LIPO_RIDER" gate="G$1" pin="USB"/>
<pinref part="POWER_SWITCH" gate="G$1" pin="VUSB"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
<errors>
<approved hash="102,1,38,93,BAT,VBAT,,,,"/>
<approved hash="102,1,38,90,USB,VUSB,,,,"/>
<approved hash="102,1,153,100,VCC,5V,,,,"/>
<approved hash="102,1,153,113,VCC,5V,,,,"/>
<approved hash="102,1,153,81,VCC,5V,,,,"/>
<approved hash="102,1,40,104,5VOUT,5V,,,,"/>
<approved hash="102,1,40,101,5VIN,5V,,,,"/>
<approved hash="102,1,189,83,VIN,5V,,,,"/>
<approved hash="117,1,38,81,3V3,,,,,"/>
<approved hash="117,1,189,119,AREF,,,,,"/>
<approved hash="113,1,131.976,90.066,FRAME1,,,,,"/>
</errors>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
<note version="8.5" severity="warning">
Since Version 8.5, EAGLE supports locking for holes, vias, wires and polygons. 
The locking property on all objects of these types will not be understood in this version. 
</note>
</compatibility>
</eagle>
