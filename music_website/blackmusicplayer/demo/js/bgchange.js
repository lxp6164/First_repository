//要用到Jquery，所以要放在Jquery.js的后面

//window.arr.push("blackmusicplayer/demo/images/bg3.jpg");
//window.arr.push("blackmusicplayer/demo/images/bg4.jpg");
//window.arr.push("blackmusicplayer/demo/images/bg5.jpg");
var flag_plat = true;
function choose_plat()
{   var body = document.getElementsByTagName("body")[0]; //加[0]是指数组的第一个元素

//检测是PC还是手机
    var browser={  
    versions:function(){   
           var u = navigator.userAgent, app = navigator.appVersion;   
           return {//移动终端浏览器版本信息   
                trident: u.indexOf('Trident') > -1, //IE内核  
                presto: u.indexOf('Presto') > -1, //opera内核  
                webKit: u.indexOf('AppleWebKit') > -1, //苹果、谷歌内核  
                gecko: u.indexOf('Gecko') > -1 && u.indexOf('KHTML') == -1, //火狐内核  
                mobile: !!u.match(/AppleWebKit.*Mobile.*/), //是否为移动终端  
                ios: !!u.match(/\(i[^;]+;( U;)? CPU.+Mac OS X/), //ios终端  
                android: u.indexOf('Android') > -1 ,//|| u.indexOf('Linux') > -1, //android终端或者uc浏览器  
                iPhone: u.indexOf('iPhone') > -1 , //是否为iPhone或者QQHD浏览器  
                iPad: u.indexOf('iPad') > -1, //是否iPad    
                webApp: u.indexOf('Safari') == -1 //是否web应该程序，没有头部与底部  
            };  
         }(),  
         language:(navigator.browserLanguage || navigator.language).toLowerCase()  
    }   
//  alert("xxx");
//alert(browser.versions.mobile);
//alert(browser.versions.ios);
//alert(browser.versions.android);
//alert(browser.versions.iPhone);
//alert(browser.versions.iPad);


  if(browser.versions.mobile || browser.versions.ios || browser.versions.android ||   
    browser.versions.iPhone || browser.versions.iPad)
  {    
        flag_plat = false;      
  }

   //if(flag_plat==true)
  //    body.style.backgroundImage = "url(blackmusicplayer/demo/images/bg5.jpg)"; 
  //   else body.style.backgroundImage = "url(blackmusicplayer/demo/images/bg8.jp3g)"; 
//alert(flag_plat);
}
//window.onload = choose_plat;



var a = (3-1);
function changeBG()
{
    var body = document.getElementsByTagName("body")[0]; //加[0]是指数组的第一个元素
     // var musicplayer_positon = document.getElementById("body")[0];
      // var mpc = document.getElementById("tmp_change");   ..不行
    
    a = (a+1)%3;
    if(flag_plat==true)
    {  switch(a)
       {
          case 0:
             body.style.backgroundImage = "url(blackmusicplayer/demo/images/bg3.jpg)"; 
              //靠，还是手册有用http://www.w3school.com.cn/jquery/selector_class.asp 
              $(function () {
                 $(".ttw-music-player").css("left","370px");
              });
             break;

          case 1: body.style.backgroundImage = "url(blackmusicplayer/demo/images/bg4.jpg)";
               $(function () {
                 $(".ttw-music-player").css("left","500px");
               });
              break;
            

          case 2: body.style.backgroundImage = "url(blackmusicplayer/demo/images/bg5.jpg)"; 
               $(function () {
                 $(".ttw-music-player").css("left","530px");
               });
             break;
          
          default: break;
       }
   }
   else
    {  switch(a)
       {
          case 0:
             body.style.backgroundImage = "url(blackmusicplayer/demo/images/bg7.jpeg)"; 
             break;

          case 1: body.style.backgroundImage = "url(blackmusicplayer/demo/images/bg8.jpeg)";
              break;
            

          case 2: body.style.backgroundImage = "url(blackmusicplayer/demo/images/bg9.jpeg)"; 
             break;
          
          default: break;
       }
   }

//setInterval('changeBG()', 10000);
setTimeout('changeBG()', 60000);
}
//window.onload = choose_plat;
//window.onload = changeBG;
//多个onload会覆盖
window.onload = function()
{
     choose_plat();   
   //  alert(flag_plat);
     changeBG();
}





