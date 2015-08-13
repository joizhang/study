addLoadEvent(prepareGallery);

function addLoadEvent(func) { //run more function after the page is ready
  var oldonload = window.onload;
  if (typeof window.onload != 'function') {
    window.onload = func;
  } else {
    window.onload = function() {
      oldonload();
      func();
    }
  }
}

function prepareGallery() {
  // alert("zzz");
  if (!document.getElementsByTagName) return false;
  if (!document.getElementById) return false;
  if (!document.getElementById("imageGallery")) return false;
  var gallery = document.getElementById("imageGallery");
  var links = gallery.getElementsByTagName("a");
  for(var i = 0; i < links.length; i++) {
    links[i].onclick = function() {//it is not onClick but onclick
      return showPic(this) ? false : true;
    }
    //links[i].onkeypress = links[i].onclick;
  }
  // alert(showPic(links[0]));
}

function showPic(whichpic) {
  if (!document.getElementById("placeholder")) return false;
  var source = whichpic.getAttribute("href");
  var placeholder = document.getElementById("placeholder");
  if (placeholder.nodeName != "IMG") return false;
  placeholder.setAttribute("src",source);
  //alert(description.childNodes[0].nodeValue);
  // alert(description.firstChild.nodeValue);
  if (document.getElementById("description")) {
    var text = whichpic.getAttribute("title") ? whichpic.getAttribute("tittle") : "";
    var description = document.getElementById("description");
    if (description.firstChild.nodeType == 3) {
      description.firstChild.nodeValue = text;
    }
  }
  return true;
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