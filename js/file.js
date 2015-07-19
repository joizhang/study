
function showPic(whichpic) {
  var source = whichpic.getAttribute("href");
  var placeholder = document.getElementById("placeholder");
  placeholder.setAttribute("src",source);
  //alert(description.childNodes[0].nodeValue);
  // alert(description.firstChild.nodeValue);
  var text = whichpic.getAttribute("title");
  var description = document.getElementById("description");
  description.firstChild.nodeValue = text;
}
/*
function countBodyChidren() {
  var body_element = document.getElementsByTagName("body").[0];
  alert(body_element);
  window.onload = countBodyChidren;
}
}
/**********************************************
function getElementByClassName(node, classname) {
  if (node.getElementByClassName) {
    return node.getElementByClassName(classname);
  } else {
    var results = new Array();
    var elems = node.getElementsByTagName("*");
    for (var i = 0; i < elems.length; i++) {
      if(elems[i].className.indexOf(classname) != -1) {
        results[results.length] = elems[i];
      }
    }
    return results;
  }
}
*********************************************
var shopping = document.getElementById("purchase");
var sales = getElementByClassName(shopping, "sale");
alert (sales);
var shopping = document.getElementById("purchase");
var items = shopping.getElementsByTagName("*")
alert (items.length);
for(var i = 0; i < items.length; i++)
  alert(typeof items[i]);*/