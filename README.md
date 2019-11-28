# OnSight
OnSight Hack Western 2019

OnSight is a fully integrate end-to-end solution for first responders. The project consists of three parts, a speech-to-text parser developed using Voiceflow API to extract crucial information from 911 calls which are then uploaded to Google Firebase, a front-end UI for control center personnel to montior all current and ongoing situations. At the center of all of this is a pair of IoT enabled smart glasses with the capability of extracting the crucial information from Google Firebase and displaying it in real time on the smart glasses for first responders to see. 

More information regarding the project can be found here: https://devpost.com/software/onsight

Inspiration
The 2016 Fort McMurray wildfires were the worst in Albertan history. It was a transformational moment for the lives of thousands of Albertans, including us. The impact that this event had on us, combined with our passion for technology, inspired us to come up with novel approaches to disaster response — a field that is relatively lacking in new technology.

What it does
OnSight is a fully integrated end-to-end solution that connects first responders, coordinators, and citizens into one centralized disaster response coordination system. As citizens make 911 calls, the Google Assistant or Amazon Alexa can extract important details which are transmitted to a Realtime Database in the cloud. These reports are processed using the Google Places API to obtain the exact location of the issue. The details of these reports, along with a map showing their locations, are displayed on a web portal. Control Centre personnel can monitor these reports in realtime and relay them to first responders. First responders are equipped with IoT smart glasses, which connect to nearby Wi-Fi networks and pull new data from the database in real time. The data is processed on the edge, where it is intelligently parsed and displayed according to priority.

How I built it
Voice recognition: The conversational functionality of this component was built using Voiceflow and integrated into the Google Assistant and Amazon Alexa. The Google Places API and Firebase Database were integrated into Voiceflow using the REST protocol.

Dashboard: We built the dashboard using Vue.js. It pulls data from the database in realtime and dynamically populates the page with the newest and highest priority reports. Along with these reports, a interactive map of the location of the report is displayed.

Smart Glasses: The brain of the smart glasses is a NodeMCU ESP8266, which is an IoT-enabled development board that runs on the Arduino framework. The board is connected to an SSD1306 OLED screen, which is reflected and magnified using a series of mirrors and lenses such that it appears in the wearer's field of view.

Challenges I ran into
The biggest challenge we ran into with this project was getting the right magnification for the optics system. Despite our high-school level of optics education, we did not calculated the required lens parameters correctly. As a result, we had to mount our system farther forward on the glasses than we anticipated. Had we chosen a more appropriate magnification, the system could be mounted much farther back, resulting in a slimmer profile. Parsing JSON objects from the Firebase Database on the glasses also proved to be quite difficult, due to the low-level nature of the C programming language used on the NodeMCU.

Accomplishments that I'm proud of
Each member of our team worked to develop separate parts of the system. Not only were we able to get all three parts working, but we were also able to integrate them through various handshake protocols. The planning and coordination of this project is something that we are very proud of.
