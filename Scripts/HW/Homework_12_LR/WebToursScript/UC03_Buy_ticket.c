UC03_Buy_ticket()
{

	lr_start_transaction("UC03_Buy_ticket");

		lr_start_transaction("UC03_01_Home_page");

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
		"Snapshot=t125.inf", 
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
		"Snapshot=t126.inf", 
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
		"Snapshot=t127.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t128.inf", 
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
		"Snapshot=t129.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC03_01_Home_page", LR_AUTO);


	lr_start_transaction("UC03_02_Login");

		web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(23);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home",
		"Snapshot=t130.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=userSession", "Value={userSession_1}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=58", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);


	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t131.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t132.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC03_02_Login", LR_AUTO);


	lr_start_transaction("UC03_03_Search_ticket");

		web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(18);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User has returned to the search page.",
		LAST);

	web_url("Search Flights Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t133.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("reservations.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/reservations.pl?page=welcome", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t134.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t135.inf", 
		"Mode=HTTP", 
		LAST);
	
	lr_end_transaction("UC03_03_Search_ticket", LR_AUTO);

	lr_start_transaction("UC03_04_Select_date");

		/* select date */

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(51);
	
	web_reg_save_param_ex(
		"ParamName=outboundFlight",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=\" checked",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/reservations.pl*",
		LAST);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"seatType\" value=\"{seatType}\" ",
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t136.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=3", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=40", ENDITEM, 
		"Name=findFlights.y", "Value=5", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);
	web_set_max_html_param_len("99999999");

	lr_end_transaction("UC03_04_Select_date", LR_AUTO);
	

	lr_start_transaction("UC03_05_Select_time");

		/* select time */

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(20);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"firstName\" value=\"{Login}\"",
		LAST);

	web_submit_data("reservations.pl_3", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Snapshot=t138.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
		"Name=numPassengers", "Value=3", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=72", ENDITEM, 
		"Name=reserveFlights.y", "Value=9", ENDITEM, 
		LAST);


	lr_end_transaction("UC03_05_Select_time", LR_AUTO);

	lr_start_transaction("UC03_06_Payment_detaills");

		/* Payment Details */

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(20);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Thank you for booking through Web Tours.",
		LAST);

	web_submit_data("reservations.pl_4", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Snapshot=t140.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=firstName", "Value={Login}", ENDITEM, 
		"Name=lastName", "Value={Password}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=pass1", "Value={pass1}", ENDITEM, 
		"Name=pass2", "Value={pass1}1", ENDITEM, 
		"Name=pass3", "Value={pass1}2", ENDITEM, 
		"Name=creditCard", "Value={creditCard}", ENDITEM, 
		"Name=expDate", "Value={expDate}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=3", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=28", ENDITEM, 
		"Name=buyFlights.y", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");


	lr_end_transaction("UC03_06_Payment_detaills", LR_AUTO);

	lr_start_transaction("UC03_07_Tickets_list");

		lr_think_time(16);

	web_url("Itinerary Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t142.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_4", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t143.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
		
		web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text= {Login} {Password}",
		LAST);

	web_url("itinerary.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/itinerary.pl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t145.inf", 
		"Mode=HTTP", 
		LAST);

	/* exit */

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(12);


	lr_end_transaction("UC03_07_Tickets_list", LR_AUTO);

	lr_start_transaction("UC03_08_Sign_off");

		web_url("SignOff Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t149.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html_2", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t150.inf", 
		"Mode=HTTP", 
		LAST);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=<title>Web Tours Navigation Bar</title>",
		LAST);

	web_url("nav.pl_5", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t151.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC03_08_Sign_off", LR_AUTO);

	lr_end_transaction("UC03_Buy_ticket", LR_AUTO);



	return 0;
}