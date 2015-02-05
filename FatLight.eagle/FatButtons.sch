<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.2.0">
<drawing>
<settings>
<setting alwaysvectorfont="yes"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
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
<library name="switch-omron">
<description>&lt;b&gt;Omron Switches&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="B3F-10XX">
<description>&lt;b&gt;OMRON SWITCH&lt;/b&gt;</description>
<wire x1="3.302" y1="-0.762" x2="3.048" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="3.302" y1="-0.762" x2="3.302" y2="0.762" width="0.1524" layer="21"/>
<wire x1="3.048" y1="0.762" x2="3.302" y2="0.762" width="0.1524" layer="21"/>
<wire x1="3.048" y1="1.016" x2="3.048" y2="2.54" width="0.1524" layer="51"/>
<wire x1="-3.302" y1="0.762" x2="-3.048" y2="0.762" width="0.1524" layer="21"/>
<wire x1="-3.302" y1="0.762" x2="-3.302" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="-3.048" y1="-0.762" x2="-3.302" y2="-0.762" width="0.1524" layer="21"/>
<wire x1="3.048" y1="2.54" x2="2.54" y2="3.048" width="0.1524" layer="51"/>
<wire x1="2.54" y1="-3.048" x2="3.048" y2="-2.54" width="0.1524" layer="51"/>
<wire x1="3.048" y1="-2.54" x2="3.048" y2="-1.016" width="0.1524" layer="51"/>
<wire x1="-2.54" y1="3.048" x2="-3.048" y2="2.54" width="0.1524" layer="51"/>
<wire x1="-3.048" y1="2.54" x2="-3.048" y2="1.016" width="0.1524" layer="51"/>
<wire x1="-2.54" y1="-3.048" x2="-3.048" y2="-2.54" width="0.1524" layer="51"/>
<wire x1="-3.048" y1="-2.54" x2="-3.048" y2="-1.016" width="0.1524" layer="51"/>
<wire x1="-1.27" y1="1.27" x2="-1.27" y2="-1.27" width="0.0508" layer="51"/>
<wire x1="1.27" y1="-1.27" x2="-1.27" y2="-1.27" width="0.0508" layer="51"/>
<wire x1="1.27" y1="-1.27" x2="1.27" y2="1.27" width="0.0508" layer="51"/>
<wire x1="-1.27" y1="1.27" x2="1.27" y2="1.27" width="0.0508" layer="51"/>
<wire x1="-1.27" y1="3.048" x2="-1.27" y2="2.794" width="0.0508" layer="21"/>
<wire x1="1.27" y1="2.794" x2="-1.27" y2="2.794" width="0.0508" layer="21"/>
<wire x1="1.27" y1="2.794" x2="1.27" y2="3.048" width="0.0508" layer="21"/>
<wire x1="1.143" y1="-2.794" x2="-1.27" y2="-2.794" width="0.0508" layer="21"/>
<wire x1="1.143" y1="-2.794" x2="1.143" y2="-3.048" width="0.0508" layer="21"/>
<wire x1="-1.27" y1="-2.794" x2="-1.27" y2="-3.048" width="0.0508" layer="21"/>
<wire x1="2.54" y1="-3.048" x2="2.159" y2="-3.048" width="0.1524" layer="51"/>
<wire x1="-2.54" y1="-3.048" x2="-2.159" y2="-3.048" width="0.1524" layer="51"/>
<wire x1="-2.159" y1="-3.048" x2="-1.27" y2="-3.048" width="0.1524" layer="21"/>
<wire x1="-2.54" y1="3.048" x2="-2.159" y2="3.048" width="0.1524" layer="51"/>
<wire x1="2.54" y1="3.048" x2="2.159" y2="3.048" width="0.1524" layer="51"/>
<wire x1="2.159" y1="3.048" x2="1.27" y2="3.048" width="0.1524" layer="21"/>
<wire x1="1.27" y1="3.048" x2="-1.27" y2="3.048" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="3.048" x2="-2.159" y2="3.048" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-3.048" x2="1.143" y2="-3.048" width="0.1524" layer="21"/>
<wire x1="1.143" y1="-3.048" x2="2.159" y2="-3.048" width="0.1524" layer="21"/>
<wire x1="3.048" y1="-0.762" x2="3.048" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="3.048" y1="0.762" x2="3.048" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-3.048" y1="-0.762" x2="-3.048" y2="-1.016" width="0.1524" layer="21"/>
<wire x1="-3.048" y1="0.762" x2="-3.048" y2="1.016" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-2.159" x2="1.27" y2="-2.159" width="0.1524" layer="51"/>
<wire x1="1.27" y1="2.286" x2="-1.27" y2="2.286" width="0.1524" layer="51"/>
<wire x1="-2.413" y1="1.27" x2="-2.413" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-2.413" y1="-0.508" x2="-2.413" y2="-1.27" width="0.1524" layer="51"/>
<wire x1="-2.413" y1="0.508" x2="-2.159" y2="-0.381" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="1.778" width="0.1524" layer="21"/>
<circle x="-2.159" y="-2.159" radius="0.508" width="0.1524" layer="51"/>
<circle x="2.159" y="-2.032" radius="0.508" width="0.1524" layer="51"/>
<circle x="2.159" y="2.159" radius="0.508" width="0.1524" layer="51"/>
<circle x="-2.159" y="2.159" radius="0.508" width="0.1524" layer="51"/>
<circle x="0" y="0" radius="0.635" width="0.0508" layer="51"/>
<circle x="0" y="0" radius="0.254" width="0.1524" layer="21"/>
<pad name="1" x="-3.2512" y="2.2606" drill="1.016" shape="long"/>
<pad name="3" x="-3.2512" y="-2.2606" drill="1.016" shape="long"/>
<pad name="2" x="3.2512" y="2.2606" drill="1.016" shape="long"/>
<pad name="4" x="3.2512" y="-2.2606" drill="1.016" shape="long"/>
<text x="-3.048" y="3.683" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-3.048" y="-5.08" size="1.27" layer="27" ratio="10">&gt;VALUE</text>
<text x="-4.318" y="1.651" size="1.27" layer="51" ratio="10">1</text>
<text x="3.556" y="1.524" size="1.27" layer="51" ratio="10">2</text>
<text x="-4.572" y="-2.794" size="1.27" layer="51" ratio="10">3</text>
<text x="3.556" y="-2.794" size="1.27" layer="51" ratio="10">4</text>
</package>
</packages>
<symbols>
<symbol name="TS2">
<wire x1="0" y1="1.905" x2="0" y2="2.54" width="0.254" layer="94"/>
<wire x1="-4.445" y1="1.905" x2="-3.175" y2="1.905" width="0.254" layer="94"/>
<wire x1="-4.445" y1="-1.905" x2="-3.175" y2="-1.905" width="0.254" layer="94"/>
<wire x1="-4.445" y1="1.905" x2="-4.445" y2="0" width="0.254" layer="94"/>
<wire x1="-4.445" y1="0" x2="-4.445" y2="-1.905" width="0.254" layer="94"/>
<wire x1="-2.54" y1="0" x2="-1.905" y2="0" width="0.1524" layer="94"/>
<wire x1="-1.27" y1="0" x2="-0.635" y2="0" width="0.1524" layer="94"/>
<wire x1="-4.445" y1="0" x2="-3.175" y2="0" width="0.1524" layer="94"/>
<wire x1="2.54" y1="2.54" x2="0" y2="2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="0" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="1.905" width="0.254" layer="94"/>
<circle x="0" y="-2.54" radius="0.127" width="0.4064" layer="94"/>
<circle x="0" y="2.54" radius="0.127" width="0.4064" layer="94"/>
<text x="-6.35" y="-2.54" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="-3.81" y="3.175" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="P" x="0" y="-5.08" visible="pad" length="short" direction="pas" swaplevel="2" rot="R90"/>
<pin name="S" x="0" y="5.08" visible="pad" length="short" direction="pas" swaplevel="1" rot="R270"/>
<pin name="S1" x="2.54" y="5.08" visible="pad" length="short" direction="pas" swaplevel="1" rot="R270"/>
<pin name="P1" x="2.54" y="-5.08" visible="pad" length="short" direction="pas" swaplevel="2" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="10-XX" prefix="S" uservalue="yes">
<description>&lt;b&gt;OMRON SWITCH&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="TS2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="B3F-10XX">
<connects>
<connect gate="1" pin="P" pad="3"/>
<connect gate="1" pin="P1" pad="4"/>
<connect gate="1" pin="S" pad="1"/>
<connect gate="1" pin="S1" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="B3F-1000" constant="no"/>
<attribute name="OC_FARNELL" value="176432" constant="no"/>
<attribute name="OC_NEWARK" value="36M3542" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-molex">
<description>&lt;b&gt;Molex Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="7395-08">
<description>&lt;b&gt;MOLEX 2.54mm KK RA CONNECTOR&lt;/b&gt;
&lt;br&gt;Fixed Orientation</description>
<wire x1="10.16" y1="-5.08" x2="10.16" y2="-1.905" width="0.254" layer="21"/>
<wire x1="10.16" y1="-1.905" x2="9.525" y2="-1.905" width="0.254" layer="21"/>
<wire x1="9.525" y1="-1.905" x2="9.525" y2="-2.54" width="0.254" layer="21"/>
<wire x1="9.525" y1="-2.54" x2="8.255" y2="-2.54" width="0.254" layer="21"/>
<wire x1="8.255" y1="-2.54" x2="8.255" y2="-1.905" width="0.254" layer="21"/>
<wire x1="8.255" y1="-1.905" x2="6.985" y2="-1.905" width="0.254" layer="21"/>
<wire x1="6.985" y1="-1.905" x2="6.985" y2="-2.54" width="0.254" layer="21"/>
<wire x1="6.985" y1="-2.54" x2="5.715" y2="-2.54" width="0.254" layer="21"/>
<wire x1="5.715" y1="-2.54" x2="5.715" y2="-1.905" width="0.254" layer="21"/>
<wire x1="5.715" y1="-1.905" x2="4.445" y2="-1.905" width="0.254" layer="21"/>
<wire x1="4.445" y1="-1.905" x2="4.445" y2="-2.54" width="0.254" layer="21"/>
<wire x1="4.445" y1="-2.54" x2="3.175" y2="-2.54" width="0.254" layer="21"/>
<wire x1="3.175" y1="-2.54" x2="3.175" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-3.175" y1="-1.905" x2="-3.175" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-3.175" y1="-2.54" x2="-4.445" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-4.445" y1="-2.54" x2="-4.445" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-4.445" y1="-1.905" x2="-5.715" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-5.715" y1="-1.905" x2="-5.715" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-5.715" y1="-2.54" x2="-6.985" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-6.985" y1="-2.54" x2="-6.985" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-6.985" y1="-1.905" x2="-8.255" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-8.255" y1="-1.905" x2="-8.255" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-8.255" y1="-2.54" x2="-9.525" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-9.525" y1="-2.54" x2="-9.525" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-9.525" y1="-1.905" x2="-10.16" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-10.16" y1="-1.905" x2="-10.16" y2="-5.08" width="0.254" layer="21"/>
<wire x1="-10.16" y1="-5.08" x2="-9.271" y2="-5.08" width="0.254" layer="21"/>
<wire x1="-9.271" y1="-5.08" x2="-1.651" y2="-5.08" width="0.254" layer="21"/>
<wire x1="-1.651" y1="-5.08" x2="0.889" y2="-5.08" width="0.254" layer="21"/>
<wire x1="0.889" y1="-5.08" x2="3.429" y2="-5.08" width="0.254" layer="21"/>
<wire x1="3.429" y1="-5.08" x2="3.7592" y2="-5.08" width="0.127" layer="21"/>
<wire x1="3.7592" y1="-5.08" x2="8.89" y2="-5.08" width="0.254" layer="21"/>
<wire x1="8.89" y1="-5.08" x2="10.16" y2="-5.08" width="0.254" layer="21"/>
<wire x1="8.89" y1="-5.08" x2="8.89" y2="-13.081" width="0.254" layer="21"/>
<wire x1="8.89" y1="-13.081" x2="8.636" y2="-13.589" width="0.254" layer="21"/>
<wire x1="8.636" y1="-13.589" x2="3.7592" y2="-13.589" width="0.254" layer="21"/>
<wire x1="3.7592" y1="-13.589" x2="3.7592" y2="-11.6586" width="0.254" layer="21"/>
<wire x1="3.7592" y1="-11.6586" x2="3.7592" y2="-5.08" width="0.254" layer="21"/>
<wire x1="-8.89" y1="-5.08" x2="-8.89" y2="-13.081" width="0.254" layer="21"/>
<wire x1="-8.89" y1="-13.081" x2="-8.636" y2="-13.589" width="0.254" layer="21"/>
<wire x1="-8.636" y1="-13.589" x2="-3.7592" y2="-13.589" width="0.254" layer="21"/>
<wire x1="-3.7592" y1="-13.589" x2="-3.7592" y2="-5.08" width="0.254" layer="21"/>
<wire x1="3.81" y1="-5.08" x2="3.429" y2="-5.08" width="0.254" layer="51"/>
<wire x1="3.429" y1="-5.08" x2="3.429" y2="-11.303" width="0.254" layer="21"/>
<wire x1="3.429" y1="-11.303" x2="3.7592" y2="-11.6586" width="0.254" layer="21"/>
<wire x1="-9.271" y1="-5.08" x2="-9.271" y2="-11.303" width="0.254" layer="21"/>
<wire x1="-9.271" y1="-11.303" x2="-8.9408" y2="-11.6586" width="0.254" layer="21"/>
<wire x1="9.271" y1="-5.08" x2="9.271" y2="-11.303" width="0.254" layer="21"/>
<wire x1="9.271" y1="-11.303" x2="8.9408" y2="-11.6586" width="0.254" layer="21"/>
<wire x1="-3.429" y1="-5.08" x2="-3.429" y2="-11.303" width="0.254" layer="21"/>
<wire x1="-3.429" y1="-11.303" x2="-3.7592" y2="-11.6586" width="0.254" layer="21"/>
<wire x1="3.175" y1="-1.905" x2="1.905" y2="-1.905" width="0.254" layer="21"/>
<wire x1="1.905" y1="-1.905" x2="1.905" y2="-2.54" width="0.254" layer="21"/>
<wire x1="1.905" y1="-2.54" x2="0.635" y2="-2.54" width="0.254" layer="21"/>
<wire x1="0.635" y1="-2.54" x2="0.635" y2="-1.905" width="0.254" layer="21"/>
<wire x1="1.651" y1="-5.08" x2="1.651" y2="-11.303" width="0.254" layer="21"/>
<wire x1="1.651" y1="-11.303" x2="1.3208" y2="-11.6586" width="0.254" layer="21"/>
<wire x1="0.889" y1="-5.08" x2="0.889" y2="-11.303" width="0.254" layer="21"/>
<wire x1="0.889" y1="-11.303" x2="1.2192" y2="-11.6586" width="0.254" layer="21"/>
<wire x1="0.635" y1="-1.905" x2="-0.635" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-0.635" y1="-1.905" x2="-0.635" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-0.635" y1="-2.54" x2="-1.905" y2="-2.54" width="0.254" layer="21"/>
<wire x1="-1.905" y1="-2.54" x2="-1.905" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-1.905" y1="-1.905" x2="-3.175" y2="-1.905" width="0.254" layer="21"/>
<wire x1="-0.889" y1="-5.08" x2="-0.889" y2="-11.303" width="0.254" layer="21"/>
<wire x1="-0.889" y1="-11.303" x2="-1.2192" y2="-11.6586" width="0.254" layer="21"/>
<wire x1="-1.651" y1="-5.08" x2="-1.651" y2="-11.303" width="0.254" layer="21"/>
<wire x1="-1.651" y1="-11.303" x2="-1.3208" y2="-11.6586" width="0.254" layer="21"/>
<pad name="1" x="8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="-6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="8" x="-8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="10.2601" y="2.9479" size="1.016" layer="25" ratio="10" rot="R180">&gt;NAME</text>
<text x="8.4059" y="-3.4021" size="1.27" layer="21" ratio="14" rot="R270">1</text>
<text x="-9.3233" y="-3.2751" size="1.27" layer="21" ratio="14" rot="R270">8</text>
<text x="-4.9799" y="2.9479" size="0.8128" layer="27" ratio="10" rot="R180">&gt;VALUE</text>
<rectangle x1="8.636" y1="-0.254" x2="9.144" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="-9.144" y1="-0.254" x2="-8.636" y2="0.254" layer="51"/>
<rectangle x1="8.636" y1="-2.5146" x2="9.144" y2="-0.2794" layer="51"/>
<rectangle x1="6.096" y1="-2.5146" x2="6.604" y2="-0.2794" layer="51"/>
<rectangle x1="3.556" y1="-2.5146" x2="4.064" y2="-0.2794" layer="51"/>
<rectangle x1="-4.064" y1="-2.5146" x2="-3.556" y2="-0.2794" layer="51"/>
<rectangle x1="-6.604" y1="-2.5146" x2="-6.096" y2="-0.2794" layer="51"/>
<rectangle x1="-9.144" y1="-2.5146" x2="-8.636" y2="-0.2794" layer="51"/>
<rectangle x1="1.016" y1="-2.5146" x2="1.524" y2="-0.2794" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-2.5146" x2="-1.016" y2="-0.2794" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
</package>
<package name="6410-08">
<description>&lt;b&gt;MOLEX 2.54mm KK  CONNECTOR&lt;/b&gt;</description>
<wire x1="-8.89" y1="2.54" x2="-8.89" y2="2.921" width="0.127" layer="21"/>
<wire x1="-10.16" y1="0" x2="-10.16" y2="2.921" width="0.254" layer="21"/>
<wire x1="-10.16" y1="2.921" x2="-8.89" y2="2.921" width="0.254" layer="21"/>
<wire x1="-8.89" y1="2.921" x2="-8.636" y2="2.921" width="0.254" layer="21"/>
<wire x1="-8.636" y1="2.921" x2="-3.81" y2="2.921" width="0.254" layer="21"/>
<wire x1="-3.81" y1="2.921" x2="-2.54" y2="2.921" width="0.254" layer="21"/>
<wire x1="10.16" y1="0" x2="10.16" y2="2.921" width="0.254" layer="21"/>
<wire x1="10.16" y1="2.921" x2="-2.54" y2="2.921" width="0.127" layer="21"/>
<wire x1="-10.16" y1="0" x2="-10.16" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-10.16" y1="-2.921" x2="-2.667" y2="-2.921" width="0.254" layer="21"/>
<wire x1="10.16" y1="0" x2="10.16" y2="-2.921" width="0.254" layer="21"/>
<wire x1="10.16" y1="-2.921" x2="-2.667" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-9.906" y1="-2.921" x2="-9.525" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-9.525" y1="-2.921" x2="-9.525" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-9.525" y1="-2.286" x2="-8.255" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-8.255" y1="-2.286" x2="-8.255" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-8.255" y1="-2.921" x2="-6.985" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-6.985" y1="-2.921" x2="-6.985" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-6.985" y1="-2.286" x2="-5.715" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-5.715" y1="-2.286" x2="-5.715" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-5.715" y1="-2.921" x2="-4.445" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-4.445" y1="-2.921" x2="-4.445" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-4.445" y1="-2.286" x2="-3.175" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-3.175" y1="-2.286" x2="-3.175" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-3.175" y1="-2.921" x2="3.175" y2="-2.921" width="0.254" layer="21"/>
<wire x1="3.175" y1="-2.921" x2="3.175" y2="-2.286" width="0.254" layer="21"/>
<wire x1="3.175" y1="-2.286" x2="4.445" y2="-2.286" width="0.254" layer="21"/>
<wire x1="4.445" y1="-2.286" x2="4.445" y2="-2.921" width="0.254" layer="21"/>
<wire x1="4.445" y1="-2.921" x2="5.715" y2="-2.921" width="0.254" layer="21"/>
<wire x1="5.715" y1="-2.921" x2="5.715" y2="-2.286" width="0.254" layer="21"/>
<wire x1="5.715" y1="-2.286" x2="6.985" y2="-2.286" width="0.254" layer="21"/>
<wire x1="6.985" y1="-2.286" x2="6.985" y2="-2.921" width="0.254" layer="21"/>
<wire x1="6.985" y1="-2.921" x2="8.255" y2="-2.921" width="0.254" layer="21"/>
<wire x1="8.255" y1="-2.921" x2="8.255" y2="-2.286" width="0.254" layer="21"/>
<wire x1="8.255" y1="-2.286" x2="9.525" y2="-2.286" width="0.254" layer="21"/>
<wire x1="9.525" y1="-2.286" x2="9.525" y2="-2.921" width="0.254" layer="21"/>
<wire x1="9.525" y1="-2.921" x2="10.16" y2="-2.921" width="0.254" layer="21"/>
<wire x1="-8.89" y1="1.905" x2="-8.89" y2="2.921" width="0.254" layer="21"/>
<wire x1="-8.89" y1="1.905" x2="-8.636" y2="1.905" width="0.254" layer="21"/>
<wire x1="-8.636" y1="1.905" x2="-3.81" y2="1.905" width="0.254" layer="21"/>
<wire x1="-3.81" y1="1.905" x2="-3.81" y2="2.921" width="0.254" layer="21"/>
<wire x1="3.81" y1="1.905" x2="3.81" y2="2.921" width="0.254" layer="21"/>
<wire x1="3.81" y1="1.905" x2="8.636" y2="1.905" width="0.254" layer="21"/>
<wire x1="8.636" y1="1.905" x2="8.89" y2="1.905" width="0.254" layer="21"/>
<wire x1="8.89" y1="1.905" x2="8.89" y2="2.921" width="0.254" layer="21"/>
<wire x1="-8.89" y1="1.905" x2="-8.636" y2="1.397" width="0.254" layer="21"/>
<wire x1="-8.636" y1="1.397" x2="-4.064" y2="1.397" width="0.254" layer="21"/>
<wire x1="-4.064" y1="1.397" x2="-3.81" y2="1.905" width="0.254" layer="21"/>
<wire x1="-8.636" y1="2.921" x2="-8.636" y2="1.905" width="0.254" layer="21"/>
<wire x1="3.81" y1="1.905" x2="4.064" y2="1.397" width="0.254" layer="21"/>
<wire x1="4.064" y1="1.397" x2="8.636" y2="1.397" width="0.254" layer="21"/>
<wire x1="8.636" y1="1.397" x2="8.89" y2="1.905" width="0.254" layer="21"/>
<wire x1="8.636" y1="2.921" x2="8.636" y2="1.905" width="0.254" layer="21"/>
<wire x1="-1.905" y1="-2.921" x2="-1.905" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-1.905" y1="-2.286" x2="-0.635" y2="-2.286" width="0.254" layer="21"/>
<wire x1="-0.635" y1="-2.286" x2="-0.635" y2="-2.921" width="0.254" layer="21"/>
<wire x1="0.635" y1="-2.921" x2="0.635" y2="-2.286" width="0.254" layer="21"/>
<wire x1="0.635" y1="-2.286" x2="1.905" y2="-2.286" width="0.254" layer="21"/>
<wire x1="1.905" y1="-2.286" x2="1.905" y2="-2.921" width="0.254" layer="21"/>
<pad name="8" x="-8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="7" x="-6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="6" x="-3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="3" x="3.81" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="2" x="6.35" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="1" x="8.89" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="5" x="-1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1.016" shape="long" rot="R90"/>
<text x="-10.0061" y="-4.7259" size="1.016" layer="25" ratio="10">&gt;NAME</text>
<text x="10.5141" y="-0.4841" size="1.27" layer="21" ratio="14">1</text>
<text x="-11.3299" y="-0.5603" size="1.27" layer="21" ratio="14">8</text>
<text x="3.3289" y="-4.7259" size="0.8128" layer="27" ratio="10">&gt;VALUE</text>
<rectangle x1="-9.144" y1="-0.254" x2="-8.636" y2="0.254" layer="51"/>
<rectangle x1="-6.604" y1="-0.254" x2="-6.096" y2="0.254" layer="51"/>
<rectangle x1="-4.064" y1="-0.254" x2="-3.556" y2="0.254" layer="51"/>
<rectangle x1="3.556" y1="-0.254" x2="4.064" y2="0.254" layer="51"/>
<rectangle x1="6.096" y1="-0.254" x2="6.604" y2="0.254" layer="51"/>
<rectangle x1="8.636" y1="-0.254" x2="9.144" y2="0.254" layer="51"/>
<rectangle x1="-1.524" y1="-0.254" x2="-1.016" y2="0.254" layer="51"/>
<rectangle x1="1.016" y1="-0.254" x2="1.524" y2="0.254" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="MV">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<text x="-0.762" y="1.397" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="M">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="22-?-08" prefix="J">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
wire to board 2.54 mm (.1 inch) pitch header</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="15.24" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="10.16" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="0" y="5.08" addlevel="always" swaplevel="1"/>
<gate name="-4" symbol="M" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-5" symbol="M" x="0" y="-5.08" addlevel="always" swaplevel="1"/>
<gate name="-6" symbol="M" x="0" y="-10.16" addlevel="always" swaplevel="1"/>
<gate name="-7" symbol="M" x="0" y="-15.24" addlevel="always" swaplevel="1"/>
<gate name="-8" symbol="M" x="0" y="-20.32" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="05-7088" package="7395-08">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
<device name="27-2081" package="6410-08">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="S1" library="switch-omron" deviceset="10-XX" device=""/>
<part name="S2" library="switch-omron" deviceset="10-XX" device=""/>
<part name="S3" library="switch-omron" deviceset="10-XX" device=""/>
<part name="S4" library="switch-omron" deviceset="10-XX" device=""/>
<part name="S5" library="switch-omron" deviceset="10-XX" device=""/>
<part name="S6" library="switch-omron" deviceset="10-XX" device=""/>
<part name="X1" library="con-molex" deviceset="22-?-08" device="05-7088"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="S1" gate="1" x="20.32" y="68.58"/>
<instance part="S2" gate="1" x="35.56" y="68.58"/>
<instance part="S3" gate="1" x="50.8" y="68.58"/>
<instance part="S4" gate="1" x="66.04" y="68.58"/>
<instance part="S5" gate="1" x="81.28" y="68.58"/>
<instance part="S6" gate="1" x="99.06" y="68.58"/>
<instance part="X1" gate="-1" x="0" y="73.66" rot="R180"/>
<instance part="X1" gate="-2" x="0" y="76.2" rot="R180"/>
<instance part="X1" gate="-3" x="0" y="78.74" rot="R180"/>
<instance part="X1" gate="-4" x="0" y="81.28" rot="R180"/>
<instance part="X1" gate="-5" x="0" y="83.82" rot="R180"/>
<instance part="X1" gate="-6" x="0" y="86.36" rot="R180"/>
<instance part="X1" gate="-7" x="0" y="88.9" rot="R180"/>
<instance part="X1" gate="-8" x="0" y="91.44" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="S6" gate="1" pin="P1"/>
<wire x1="101.6" y1="60.96" x2="101.6" y2="63.5" width="0.1524" layer="91"/>
<pinref part="S6" gate="1" pin="P"/>
<wire x1="99.06" y1="63.5" x2="101.6" y2="63.5" width="0.1524" layer="91"/>
<junction x="101.6" y="63.5"/>
<wire x1="101.6" y1="60.96" x2="83.82" y2="60.96" width="0.1524" layer="91"/>
<pinref part="S5" gate="1" pin="P1"/>
<wire x1="83.82" y1="60.96" x2="83.82" y2="63.5" width="0.1524" layer="91"/>
<pinref part="S5" gate="1" pin="P"/>
<wire x1="81.28" y1="63.5" x2="83.82" y2="63.5" width="0.1524" layer="91"/>
<junction x="83.82" y="63.5"/>
<wire x1="83.82" y1="60.96" x2="68.58" y2="60.96" width="0.1524" layer="91"/>
<junction x="83.82" y="60.96"/>
<pinref part="S4" gate="1" pin="P1"/>
<wire x1="68.58" y1="60.96" x2="68.58" y2="63.5" width="0.1524" layer="91"/>
<pinref part="S4" gate="1" pin="P"/>
<wire x1="66.04" y1="63.5" x2="68.58" y2="63.5" width="0.1524" layer="91"/>
<junction x="68.58" y="63.5"/>
<wire x1="68.58" y1="60.96" x2="53.34" y2="60.96" width="0.1524" layer="91"/>
<junction x="68.58" y="60.96"/>
<pinref part="S3" gate="1" pin="P1"/>
<wire x1="53.34" y1="60.96" x2="53.34" y2="63.5" width="0.1524" layer="91"/>
<pinref part="S3" gate="1" pin="P"/>
<wire x1="50.8" y1="63.5" x2="53.34" y2="63.5" width="0.1524" layer="91"/>
<junction x="53.34" y="63.5"/>
<wire x1="53.34" y1="60.96" x2="38.1" y2="60.96" width="0.1524" layer="91"/>
<junction x="53.34" y="60.96"/>
<pinref part="S2" gate="1" pin="P1"/>
<wire x1="38.1" y1="60.96" x2="38.1" y2="63.5" width="0.1524" layer="91"/>
<pinref part="S2" gate="1" pin="P"/>
<wire x1="35.56" y1="63.5" x2="38.1" y2="63.5" width="0.1524" layer="91"/>
<junction x="38.1" y="63.5"/>
<pinref part="S1" gate="1" pin="P1"/>
<wire x1="38.1" y1="60.96" x2="22.86" y2="60.96" width="0.1524" layer="91"/>
<wire x1="22.86" y1="60.96" x2="22.86" y2="63.5" width="0.1524" layer="91"/>
<junction x="38.1" y="60.96"/>
<pinref part="S1" gate="1" pin="P"/>
<wire x1="20.32" y1="63.5" x2="22.86" y2="63.5" width="0.1524" layer="91"/>
<junction x="22.86" y="63.5"/>
<pinref part="X1" gate="-1" pin="S"/>
<wire x1="2.54" y1="73.66" x2="7.62" y2="73.66" width="0.1524" layer="91"/>
<wire x1="7.62" y1="73.66" x2="7.62" y2="60.96" width="0.1524" layer="91"/>
<wire x1="7.62" y1="60.96" x2="22.86" y2="60.96" width="0.1524" layer="91"/>
<junction x="22.86" y="60.96"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="S1" gate="1" pin="S1"/>
<pinref part="S1" gate="1" pin="S"/>
<wire x1="22.86" y1="73.66" x2="20.32" y2="73.66" width="0.1524" layer="91"/>
<pinref part="X1" gate="-3" pin="S"/>
<wire x1="2.54" y1="78.74" x2="22.86" y2="78.74" width="0.1524" layer="91"/>
<wire x1="22.86" y1="78.74" x2="22.86" y2="73.66" width="0.1524" layer="91"/>
<junction x="22.86" y="73.66"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="S2" gate="1" pin="S1"/>
<pinref part="S2" gate="1" pin="S"/>
<wire x1="38.1" y1="73.66" x2="35.56" y2="73.66" width="0.1524" layer="91"/>
<pinref part="X1" gate="-4" pin="S"/>
<wire x1="2.54" y1="81.28" x2="38.1" y2="81.28" width="0.1524" layer="91"/>
<wire x1="38.1" y1="81.28" x2="38.1" y2="73.66" width="0.1524" layer="91"/>
<junction x="38.1" y="73.66"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="S3" gate="1" pin="S1"/>
<pinref part="S3" gate="1" pin="S"/>
<wire x1="53.34" y1="73.66" x2="50.8" y2="73.66" width="0.1524" layer="91"/>
<pinref part="X1" gate="-5" pin="S"/>
<wire x1="2.54" y1="83.82" x2="53.34" y2="83.82" width="0.1524" layer="91"/>
<wire x1="53.34" y1="83.82" x2="53.34" y2="73.66" width="0.1524" layer="91"/>
<junction x="53.34" y="73.66"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="S4" gate="1" pin="S1"/>
<pinref part="S4" gate="1" pin="S"/>
<wire x1="68.58" y1="73.66" x2="66.04" y2="73.66" width="0.1524" layer="91"/>
<pinref part="X1" gate="-6" pin="S"/>
<wire x1="2.54" y1="86.36" x2="68.58" y2="86.36" width="0.1524" layer="91"/>
<wire x1="68.58" y1="86.36" x2="68.58" y2="73.66" width="0.1524" layer="91"/>
<junction x="68.58" y="73.66"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="S5" gate="1" pin="S1"/>
<pinref part="S5" gate="1" pin="S"/>
<wire x1="83.82" y1="73.66" x2="81.28" y2="73.66" width="0.1524" layer="91"/>
<pinref part="X1" gate="-7" pin="S"/>
<wire x1="2.54" y1="88.9" x2="83.82" y2="88.9" width="0.1524" layer="91"/>
<wire x1="83.82" y1="88.9" x2="83.82" y2="73.66" width="0.1524" layer="91"/>
<junction x="83.82" y="73.66"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="S6" gate="1" pin="S1"/>
<pinref part="S6" gate="1" pin="S"/>
<wire x1="101.6" y1="73.66" x2="99.06" y2="73.66" width="0.1524" layer="91"/>
<pinref part="X1" gate="-8" pin="S"/>
<wire x1="2.54" y1="91.44" x2="101.6" y2="91.44" width="0.1524" layer="91"/>
<wire x1="101.6" y1="91.44" x2="101.6" y2="73.66" width="0.1524" layer="91"/>
<junction x="101.6" y="73.66"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
