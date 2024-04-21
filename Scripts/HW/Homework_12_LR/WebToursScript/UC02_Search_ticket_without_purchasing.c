UC02_Search_ticket_without_purchasing()
{
lr_start_transaction("UC02_Search_ticket_without_purchasing");

		
	lr_start_transaction("UC02_01_Home_page");

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
		"Snapshot=t108.inf", 
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
		"Snapshot=t109.inf", 
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
		"Snapshot=t110.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t111.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC02_01_Home_page", LR_AUTO);

	lr_start_transaction("UC02_02_Login");

/*Correlation comment - Do not change!  Original value='138810.608829486HVtAAHApzQVzzzzHtcitAptctVf' Name ='userSession_1' Type ='Manual'*/
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
		"Snapshot=t112.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(28);
	
		
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home",
		"Snapshot=t113.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=userSession", "Value={userSession_1}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=41", ENDITEM,
		"Name=login.y", "Value=4", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t114.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t115.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_end_transaction("UC02_02_Login", LR_AUTO);


	lr_think_time(22);

	lr_start_transaction("UC02_03_Ticket_search");
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User has returned to the search page.",
		LAST);


		web_url("Search Flights Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t116.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t117.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("reservations.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/reservations.pl?page=welcome", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=search", 
		"Snapshot=t119.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC02_03_Ticket_search", LR_AUTO);

	lr_start_transaction("UC02_04_Fill_date");

		
	web_add_auto_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(24);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"seatType\" value=\"{seatType}\" ",
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=outboundFlight",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=\" checked",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/reservations.pl*",
		LAST);

	web_submit_data("reservations.pl_2", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t123.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={depart}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arrive}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=findFlights.x", "Value=62", ENDITEM, 
		"Name=findFlights.y", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_think_time(5);

	lr_end_transaction("UC02_04_Fill_date", LR_AUTO);

lr_start_transaction("UC02_05_Select_ticket");

			web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=name=\"firstName\" value=\"{Login}\" ",
		LAST);
		
	web_submit_data("reservations.pl_3", 
		"Action={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/reservations.pl", 
		"Snapshot=t124.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=42", ENDITEM, 
		"Name=reserveFlights.y", "Value=5", ENDITEM, 
		LAST);


	lr_end_transaction("UC02_05_Select_ticket", LR_AUTO);


	lr_end_transaction("UC02_Search_ticket_without_purchasing", LR_AUTO);

	return 0;
}