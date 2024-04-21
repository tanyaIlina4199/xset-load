UC04_Tickets_list()
{

	lr_start_transaction("UC04_Tickets_list");

		lr_start_transaction("UC04_01_Home_page");

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
		"Snapshot=t152.inf", 
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
		"Snapshot=t153.inf", 
		"Mode=HTTP", 
		LAST);

		web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text= A Session ID has been created and loaded into a cookie called MSO.",
		LAST);
		
	web_url("welcome.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/", 
		"Snapshot=t154.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t155.inf", 
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
		"Snapshot=t156.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC04_01_Home_page", LR_AUTO);


	lr_start_transaction("UC04_02_Login");

		web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(24);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home",
		"Snapshot=t157.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=userSession", "Value={userSession_1}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=81", ENDITEM,
		"Name=login.y", "Value=6", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t158.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t159.inf", 
		"Mode=HTTP", 
		LAST);


	lr_end_transaction("UC04_02_Login", LR_AUTO);

	lr_start_transaction("UC04_03_Tikcets_list");

		/* tickets list */

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(29);

	web_url("Itinerary Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t160.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text={Login} {Password}",
		LAST);

	
	web_url("itinerary.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/itinerary.pl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t161.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t162.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC04_03_Tikcets_list", LR_AUTO);


	lr_start_transaction("UC04_04_Sign_off");

		/* exit */

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(23);

	web_url("SignOff Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t163.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html_2", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t164.inf", 
		"Mode=HTTP", 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=<title>Web Tours Navigation Bar</title>",
		LAST);

	web_url("nav.pl_4", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t165.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC04_04_Sign_off", LR_AUTO);

	lr_end_transaction("UC04_Tickets_list", LR_AUTO);



	return 0;
}