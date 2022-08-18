function updateSliderPWM(element) {
  const sliderValue = document.getElementById("pwmSlider").value;
  document.getElementById("textSliderValue").innerHTML = sliderValue;
  console.log(sliderValue);
  const request = new XMLHttpRequest();
  request.open("GET", "/slider?value=" + sliderValue, true);
  request.send();
}

function autoMode(element) {
  const request = new XMLHttpRequest();
  request.open("GET", "/mode?value=auto", true);
  request.send();
}

function manualMode(element) {
  const request = new XMLHttpRequest();
  request.open("GET", "/mode?value=manual", true);
  request.send();
}

function updatePageValue(element) {
  const request = new XMLHttpRequest();
  request.addEventListener("readystatechange", () => {
    // in async request, ready state 4 is when the request is fully done
    // look at xml readystatechange for what each code means
    if (request.readyState === 4) {
      const data = request.responseText;
      // design a json layout in eesp8266
      // read the data and change the body base on the data
      // change data using.innerHTML method!
    }
  });
  request.open("GET", "/status", True);
  request.send();
}
