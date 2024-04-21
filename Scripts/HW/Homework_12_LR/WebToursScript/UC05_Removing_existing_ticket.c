handle_request_params() {
    int i;
    int count = atoi(lr_eval_string("{flightIDs_count}"));
    char flightIDs_combined[1024] = "";
    char cgfields_combined[1024] = "";
    char* currentFlightID = "";

    for (i = 1; i <= count; i++) {
        char paramName[50];
        char flightIDBuffer[1024];
        char cgfieldBuffer[1024];

        sprintf(paramName, "{flightIDs_%d}", i);

        currentFlightID = lr_eval_string(paramName);

        sprintf(flightIDBuffer, "%sflightID=%s", (i == 1 ? "" : "&"), currentFlightID);

        sprintf(cgfieldBuffer, "%s.cgifields=%d", (i == 1 ? "" : "&"), i);

        strcat(flightIDs_combined, flightIDBuffer);
        strcat(cgfields_combined, cgfieldBuffer);
    }

    lr_output_message("Combined flightIDs string: %s", flightIDs_combined);
    lr_output_message("Combined .cgifields string: %s", cgfields_combined);

    lr_save_string(flightIDs_combined, "flightIDs_combined");
    lr_save_string(cgfields_combined, "cgfields_combined");

    return 0;
}



UC05_Removing_existing_ticket()
{

	lr_start_transaction("UC05_Removing_existing_ticket");

		lr_start_transaction("UC05_01_Home_page");

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
		"Snapshot=t166.inf", 
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
		"Snapshot=t167.inf", 
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
		"Snapshot=t168.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t169.inf", 
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
		"Snapshot=t170.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC05_01_Home_page", LR_AUTO);


	lr_start_transaction("UC05_02_Login");

		/* login */

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(31);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl",
		"Method=POST",
		"RecContentType=text/html",
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home",
		"Snapshot=t171.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=userSession", "Value={userSession_1}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=40", ENDITEM,
		"Name=login.y", "Value=3", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	web_url("login.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t172.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t173.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC05_02_Login", LR_AUTO);


	lr_start_transaction("UC05_03_Tickets_list");

		/* tickets list */

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(27);

	web_url("Itinerary Button", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t174.inf", 
		"Mode=HTTP", 
		LAST);
	
	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text={Login} {Password}",
		LAST);
	
	web_reg_save_param_regexp(
    	"ParamName=flightIDs",
    	"RegExp=input type=\"hidden\" name=\"flightID\" value=\"([^\"]+)\"",
    	"Ordinal=All",
    	SEARCH_FILTERS,
    	"Scope=Body",
    	LAST);

	web_url("itinerary.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/itinerary.pl", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t175.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=itinerary", 
		"Snapshot=t176.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC05_03_Tickets_list", LR_AUTO);


	lr_start_transaction("UC05_04_Remove_ticket");

		/* remove ticket */

	web_add_header("Origin", 
		"{protacol}://{host}:{port}");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(32);
	
	handle_request_params();
	web_custom_request("itinerary.pl_2",
    	"URL={protacol}://{host}:{port}/cgi-bin/itinerary.pl",
    	"Method=POST",
    	"Resource=0",
    	"RecContentType=text/html",
    	"Referer={protacol}://{host}:{port}/cgi-bin/itinerary.pl",
    	"Snapshot=t177.inf",
    	"Mode=HTTP",
    	"Body=1=on&{flightIDs_combined}&{cgfields_combined}&removeFlights.x=69&removeFlights.y=5",
    	LAST);
	

	lr_end_transaction("UC05_04_Remove_ticket", LR_AUTO);


	lr_start_transaction("UC05_05_Sign_off");

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

	lr_think_time(30);

	web_url("welcome.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t179.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_4", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t180.inf", 
		"Mode=HTTP", 
		LAST);

	lr_think_time(7);

	web_url("home.html_2", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=1", 
		"Snapshot=t181.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC05_05_Sign_off", LR_AUTO);

	lr_end_transaction("UC05_Removing_existing_ticket", LR_AUTO);



	return 0;
}