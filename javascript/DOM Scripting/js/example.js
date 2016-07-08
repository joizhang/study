//7.3
window.onload = function() {
  var placeholder = document.createElement("img");
  placeholder.setAttribute("id", "placeholder");
  placeholder.setAttribute("src", "images/placeholder.jpg");
  placeholder.setAttribute("alt", "my image gallery");
  var description = document.createElement("p");
  description.setAttribute("id", "description");
  var desctext = document.createTextNode("Choose an image");
}
/*
//7.2
window.onload = function() {
  var para = document.createElement("p");
  var txt1 = document.createTextNode("This is ");
  var emphasis = document.createElement("em");
  var txt2 = document.createTextNode("my");
  var txt3 = document.createTextNode(" content.");
  para.appendChild(txt1);
  emphasis.appendChild(txt2);
  para.appendChild(emphasis);
  para.appendChild(txt3);
  var divtest = document.getElementById("testdiv");
  divtest.appendChild(para);
}


window.onload = function() {
  var para = document.createElement("p");
  var txt = document.createTextNode("Hello World!");
  para.appendChild(txt);
  var testdiv = document.getElementById("testdiv");
  testdiv.appendChild(para);
}*/