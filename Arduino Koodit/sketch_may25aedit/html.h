HTTP/1.1 200 OK;
            Content-type:text/html;
            Connection: close;
            client.println();

            // Display the HTML web page
            <!DOCTYPE html><html>;
            <head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">;
            <link rel=\"icon\" href=\"data:,\">;


            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            <style>body {background-position: center;background-repeat: no-repeat;background-image: url(https://i.imgur.com/519xJAP.jpg);  text-align: center; font-family: \"Trebuchet MS\", Arial; margin-left:auto; margin-right:auto;};
            .slider { width: 300px; }</style>
            <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js\"></script>
                     
            // Web Page
            </head><body><h1>ESP32 with Servos</h1>
            <p>PositionLeft: <span id=\"servoPos\"></span></p>       
            <input type=\"range\" min=\"0\" max=\"180\" class=\"slider\" id=\"servoSlider\" onchange=\"servo(this.value)\" value=\""+valueString+"\"/>
            
            <p>PositionRight: <span id=\"servoPos2\"></span></p>");          
            <input type=\"range\" min=\"0\" max=\"180\" class=\"slider\" id=\"servoSlider2\" onchange=\"servo2(this.value)\" value=\""+valueString2+"\"/>
            
            <script>var slider = document.getElementById(\"servoSlider\")
            var servoP = document.getElementById(\"servoPos\"); servoP.innerHTML = slider.value;
            slider.oninput = function() { slider.value = this.value; servoP.innerHTML = this.value; }
            $.ajaxSetup({timeout:1000}); function servo(pos) { ")
            $.get(\"/?value=\" + pos + \"&\"); {Connection: close};}</script>

            <script>var slider2 = document.getElementById(\"servoSlider2\")
            var servoP2 = document.getElementById(\"servoPos2\"); servoP2.innerHTML = slider2.value;
            slider2.oninput = function() { slider2.value = this.value; servoP2.innerHTML = this.value; }
            $.ajaxSetup({timeout:1000}); function servo2(pos) { 
            $.get(\"/?value2=\" + pos + \"&\"); {Connection: close};}</script>
           
            </body></html>;     
            
