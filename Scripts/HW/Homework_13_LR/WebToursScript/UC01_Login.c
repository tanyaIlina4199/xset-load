UC01_Login()
{

	lr_start_transaction("UC01_Login");

		lr_start_transaction("UC01_01_Home_page");

		web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"103\", \".Not/A)Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("WebTours", 
		"URL={protacol}://{host}:{port}/WebTours/", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t97.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html", 
		"URL={protacol}://{host}:{port}/WebTours/header.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t98.inf", 
		"Mode=HTTP", 
		LAST);

		web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=A Session ID has been created and loaded into a cookie called MSO",
		LAST);

		
	web_url("welcome.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t99.inf", 
		"Mode=HTTP", 
		LAST);
	
	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t100.inf", 
		"Mode=HTTP", 
		LAST);
		
	web_reg_save_param_ex(
    "ParamName=userSession_1",
    "LB=name=\"userSession\" value=\"",
    "RB=\"",
    SEARCH_FILTERS,
    "Scope=Body",
    "RequestUrl=*/nav.pl*",
    LAST);

	web_url("nav.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t101.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC01_01_Home_page", LR_AUTO);


	lr_start_transaction("UC01_02_Login");

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(25);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		LAST);

	web_submit_data("login.pl", 
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t102.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession_1}", ENDITEM, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=24", ENDITEM, 
		"Name=login.y", "Value=9", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t103.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t104.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC01_02_Login", LR_AUTO);


	lr_start_transaction("UC01_03_Sign_off");

		web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(4);
	
	
	web_url("SignOff Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t105.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html_2", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t106.inf", 
		"Mode=HTTP", 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"userSession\"",
		LAST);

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t107.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC01_03_Sign_off", LR_AUTO);

	lr_end_transaction("UC01_Login", LR_AUTO);



	return 0;
}