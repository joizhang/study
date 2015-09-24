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

function insertAfter(newElement, targetElement) {
  var parent = targetElement.parentNode;
  if (parent.lastChild == targetElement) {
    parent.appendChild(newElement);
  } else {
    parent.insertBefore(newElement, targetElement.nextSilbling);
  }
}

function preparePlaceholder() {
  if(!document.createElement) return false;
  if(!document.createTextNode) return false;
  if(!document.getElementById) return false;
  if(!document.getElementById("imageGallery")) return false;
  /*placeholder*/
  var placeholder = document.createElement("img");
  placeholder.setAttribute("id", "placeholder");
  placeholder.setAttribute("src", "images/placeholder.jpg");
  placeholder.setAttribute("alt", "my image gallery");

  /*description*/
  var description = document.createElement("p");
  description.setAttribute("id", "description");
  var desctext = document.createTextNode("Choose an image");
  description.appendChild(desctext);

  // document.getElementsByTagName("body")[0].appendChild(placeholder);
  // document.getElementsByTagName("body")[0].appendChild(description);
  // document.body.appendChild(placeholder);
  // document.body.appendChild(description);

  var gallery = document.getElementById("imageGallery");
  // gallery.parentNode.insertBefore(description, gallery);
  // gallery.parentNode.insertBefore(placeholder, gallery);
  insertAfter(placeholder, gallery);
  insertAfter(description, placeholder);
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

addLoadEvent(preparePlaceholder);
addLoadEvent(prepareGallery);

