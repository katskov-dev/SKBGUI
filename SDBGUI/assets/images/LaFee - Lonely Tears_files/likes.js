﻿!function(e){function t(i){if(n[i])return n[i].exports;var r=n[i]={i:i,l:!1,exports:{}};return e[i].call(r.exports,r,r.exports,t),r.l=!0,r.exports}var n={};return t.m=e,t.c=n,t.d=function(e,n,i){t.o(e,n)||Object.defineProperty(e,n,{enumerable:!0,get:i})},t.r=function(e){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(e,"__esModule",{value:!0})},t.t=function(e,n){if(1&n&&(e=t(e)),8&n)return e;if(4&n&&"object"==typeof e&&e&&e.__esModule)return e;var i=Object.create(null);if(t.r(i),Object.defineProperty(i,"default",{enumerable:!0,value:e}),2&n&&"string"!=typeof e)for(var r in e)t.d(i,r,function(t){return e[t]}.bind(null,r));return i},t.n=function(e){var n=e&&e.__esModule?function(){return e["default"]}:function(){return e};return t.d(n,"a",n),n},t.o=function(e,t){return Object.prototype.hasOwnProperty.call(e,t)},t.p="",t(t.s=548)}({445:function(e,t,n){"use strict";n.r(t);var i=Object.assign||function(e){for(var t=1;t<arguments.length;t++){var n=arguments[t];for(var i in n)Object.prototype.hasOwnProperty.call(n,i)&&(e[i]=n[i])}return e},r=function(){function e(e,t){var n=[],i=!0,r=!1,s=void 0;try{for(var o,a=e[Symbol.iterator]();!(i=(o=a.next()).done)&&(n.push(o.value),!t||n.length!==t);i=!0);}catch(u){r=!0,s=u}finally{try{!i&&a["return"]&&a["return"]()}finally{if(r)throw s}}return n}return function(t,n){if(Array.isArray(t))return t;if(Symbol.iterator in Object(t))return e(t,n);throw new TypeError("Invalid attempt to destructure non-iterable instance")}}(),s=window,o=s.isNumeric,a=s.isUndefined,u=s.formatCount,c={like:"like",share:"share",views:"views",comment:"comment"},l={toggle:function(e,t,n,i){var r=this;cancelEvent(t);var s=hasClass(e,"active");addClass(e,"animate"),this.clientUpdate(n,c.like,s?-1:1,!s),ajax.post("like.php",{act:s?"a_do_unlike":"a_do_like",object:n,hash:i,wall:2,from:this._getReference(n)},{onDone:function(t){r.update(n,t),"wall"===n.substr(0,4)&&cur.onPostLike&&cur.onPostLike(e,n.substr(4),s)},onFail:function(){return toggleClass(e,"active",s),r.clientUpdate(n,c.like,s?1:-1,s),!1}});var o=intval(domData(e,"count"));o>0?l.showLikes(e,n,{fast:!0}):e.tt&&e.tt.destroy&&e.tt.destroy()},_parseObjectId:function(e){var t=e.match(/^([a-z_]+)([0-9\-_]+)$/),n=r(t,3),i=n[1],s=n[2];return{objectType:i,objectId:s}},_getReference:function(e){return cur.pvShown?"photo_viewer":e===cur.wallLayer?"wkview":window.mvcur&&mvcur.mvShown?"videoview":cur.wallType?"feed"===cur.wallType?"news"===cur.section?"feed_"+(cur.subsection?cur.subsection:cur.section):"recommended"===cur.section?"feed_recommended"+("recent"!==cur.subsection?"_"+cur.subsection:""):inArray(cur.section,["friends","groups","videos","photos"])?"feed_"+(cur.subsection?"_"+cur.subsection:""):"feed_"+cur.section:"top"===cur.wallType?"wall_top":"wall_"+(cur.onepost?"one":(cur.wallType||"").indexOf("full_")?"page":"full"):cur.module},share:function(e){var t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:{},n=this._parseObjectId(e),r=n.objectType,s=n.objectId;showBox("like.php",i({act:"publish_box",object:e},t),{stat:["page.js","page.css","wide_dd.js","wide_dd.css","sharebox.js"]}),"wall"===r&&Wall.triggerAdPostStat(s,"share_post"),cur.RpcMethods&&(cur.RpcMethods.likeFullUpdate=function(t){return l.update(e,window.cleanObj(t))})},clientUpdate:function(e,t,n,i){var r=this._getButtonsByType(e,t);if(r.length){var s=intval(domData(r[0],"count"))+n;this._updateDom(e,t,s,i),this.updateExternalIndex(e,{type:t,count:s,isActive:i})}},update:function(e,t){if(!isNaN(parseInt(t.like_num))){var n=a(t.like_my)?void 0:!!intval(t.like_my);this._updateDom(e,c.like,t.like_num,n,t.like_title),this.updateExternalIndex(e,{type:c.like,count:t.like_num,isActive:n})}if(!isNaN(parseInt(t.share_num))){var i=a(t.share_my)?void 0:!!intval(t.share_my);this._updateDom(e,c.share,t.share_num,i,t.share_title),this.updateExternalIndex(e,{type:c.share,count:t.share_num})}o(t.views_num)&&this._updateDom(e,c.views,t.views_num,void 0,t.views_title),o(t.comment_num)&&this._updateDom(e,c.comment,t.comment_num)},updateComments:function(e,t){this.update(e,{comment_num:t})},_updateDom:function(e,t,n,i,r){var s=this._getButtonsByType(e,t),o=t===c.views,a="";o?a=n:n>0&&(a=vk.widget?u(n):langNumeric(n,"%s",!0)),o||(n=intval(n));for(var l=0;l<s.length;l++){var d=s[l];if(!hasClass(d,"no_counter")){var p=o?s[l]:geByClass1("like_button_count",s[l]);animateCount(p,a,{str:"auto",noWrapWidth:!o,noSpaceIfEmpty:!0}),toggleClass(d,"empty",0>=n),"boolean"==typeof i&&toggleClass(d,"active",i),attr(s[l],"data-count",n),o&&attr(s[l],"title",r||"");var v=s[l].tt;if(v){var h=domByClass(v.container,"_content"),_=domByClass(v.container,"_value"),m=domByClass(v.container,"_title"),f=intval(val(_));val(_,n),r&&val(m,r),isObject(v)&&(v.likeInvalidated=!0),(f!==n&&7>f||r===!1)&&(t===c.like?d.needReinitLikesTT=!0:t===c.share&&(d.needReinitShareTT=!0)),inArray(t,[c.like,c.share])&&toggleClass(h,"me_hidden",!i),r===!1&&v.destroy&&v.destroy()}}}},_getButtonsByType:function(e,t){return domQuery("._like_"+e+" ._"+t)},showLikes:function(e,t){var n=arguments.length>2&&void 0!==arguments[2]?arguments[2]:{};if(!e.postDontShowLikes){var i=n.views?{views:1}:n.share?{published:1}:{};n.listId&&(i.list=n.listId);var r=!!geByClass1("share",gpeByClass("like_wrap",e)),s=getComputedStyle(e),o=intval(s.getPropertyValue("padding-left").replace("px","")),a=intval(s.getPropertyValue("padding-top").replace("px","")),u=geByClass1("like_button_icon",e),c=40,d=[c-getSize(u)[0]/2-o,10-a],p=n.cl||"";if(n.share)p+="likes_tt_share";else if(p+="likes_tt_like","wpost"===n.from)d[0]=12;else if("widget_community"===n.from)d[0]=6;else if("wcomments"===n.from||"widget_comments"===cur.wallType){var v=16,h=10;d[0]=getSize(e)[0]+v-getSize(u)[0]/2-h}var _=void 0,m=void 0;n.share?(_="needReinitLikesTT",m="resetLikesTTTimer"):(_="needReinitShareTT",m="resetShareTTTimer"),clearTimeout(e[m]),showTooltip(e,{url:"/like.php",params:extend({act:"a_get_stats",object:t,has_share:r?1:""},i),slide:15,shift:d,ajaxdt:n.fast?0:100,showdt:n.fast?0:400,hidedt:200,dir:"auto",checkLeft:!0,reverseOffset:80,noZIndex:!0,hasover:!0,tip:{over:function(){l.showLikes(e,t,n)}},typeClass:"like_tt",className:p,onHide:function(){clearTimeout(e[m]),e[_]&&(e[m]=setTimeout(function(){delete e[_],e.tt&&e.tt.destroy&&e.tt.destroy()},200))},appendEl:vk.widget?bodyNode:!1})}},showShare:function(e,t,n){l.showLikes(e,t,extend(n,{share:1}))},updateViews:function(e){ajax.post("like.php",{act:"a_get_stats",object:e,views:1},{cache:1,onDone:function(t,n){var i=ce("div",{innerHTML:n});l._updateDom(e,c.views,t,void 0,i.innerText||i.textContent)}})},makeTemplate:function(e,t){return t=extend({object_raw:"",likes_count:"",liked:!1,share_count:"",shared:"",views_count:"",share_opts:{},like_opts:{},class_name:"",like_cont_class:""},t),t.like_active=t.liked?"active":"",t.share_active=t.shared?"active":"",t.comment_active="",t.likes_formatted_count=t.likes_count>0?langNumeric(t.likes_count,"%s",!0):"",t.share_formatted_count=t.share_count>0?langNumeric(t.share_count,"%s",!0):"",t.share_opts=this._convertOptsToString(t.share_opts),t.like_opts=this._convertOptsToString(t.like_opts),t.like_class_name=t.likes_count>0?"":"empty",t.share_class_name=t.share_count>0?"":"empty",rs(e,t)},_convertOptsToString:function(e){return JSON.stringify(e).replace(/\"/g,"'")},updateExternalIndex:function(e){var t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:{},n=this._parseObjectId(e),i=n.objectType,r=n.objectId;switch(i){case"photo":if(!cur.pvShown||!cur.pvCurPhoto||cur.pvCurPhoto.id!==r)return;var s=cur.pvListId,o=cur.pvIndex,a=cur.pvData[s][o];t.type===c.like?(a.likes=t.count,a.liked=t.isActive,cur.pvCommsLikes[a.id][1]=t.count):t.type===c.share&&(a.shares=t.count);break;case"video":if(window.mvcur&&mvcur.mvShown&&mvcur.videoRaw===r&&t.type===c.like){var u=Videoview.getMvData();u.likes=t.count,"undefined"!=typeof t.isActive&&(u.liked=t.isActive,Videoview.playerOnLiked(t.isActive),Videoview.recache())}}},showLikesList:function(e,t){cur.viewAsBox||hasClass(gpeByClass("like_btn",e),"no_counter")||showWiki({w:"likes/"+clean(t)},!1,!1,{queue:1})},showSharesList:function(e,t){cur.viewAsBox||hasClass(gpeByClass("like_btn",e),"no_counter")||showWiki({w:"shares/"+clean(t)},!1,!1,{queue:1})}};window.Likes=l;try{stManager.done("likes.js")}catch(d){}},548:function(e,t,n){e.exports=n(445)}});