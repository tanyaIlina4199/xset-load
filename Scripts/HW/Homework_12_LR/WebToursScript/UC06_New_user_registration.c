char buff[32] = "";

random_word(char* param_name, int length)	{ 
  int r,i;
  char c;
  srand((unsigned int)time(0));

	for (i = 0; i < length; i++)	{
    	r = rand() % 26 + 97;
    	c = (char)r;
    	buff[i] = c;
    	printf("%c", c);
	}

	lr_save_string(buff, param_name);
	return 0;
}

UC06_New_user_registration()
{

	lr_start_transaction("UC06_New_user_registration");

		lr_start_transaction("UC06_01_Home_page");

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
		"Snapshot=t182.inf", 
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
		"Snapshot=t183.inf", 
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
		"Snapshot=t184.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("home.html", 
		"URL={protacol}://{host}:{port}/WebTours/home.html", 
		"Resource=0", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?signOff=true", 
		"Snapshot=t185.inf", 
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
		"Snapshot=t186.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC06_01_Home_page", LR_AUTO);


	lr_start_transaction("UC06_02_Registration");

		/* registration*/

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(29);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Please choose a username and password combination for your account.",
		LAST);
	
	web_url("login.pl", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/WebTours/home.html", 
		"Snapshot=t187.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("profileValidate.js", 
		"URL={protacol}://{host}:{port}/WebTours/profileValidate.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t188.inf", 
		LAST);

	lr_end_transaction("UC06_02_Registration", LR_AUTO);


	lr_start_transaction("UC06_03_Filling_data");

		/* filling data */

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

	lr_think_time(54);
	
	random_word("newUsername", 10);
	random_word("newPassword", 5);

	web_reg_find("Fail=NotFound",
		"Search=Body",
		"Text=Thank you, <b>{newUsername}</b>, for registering and welcome to the Web Tours family.",
		LAST);

	web_submit_data("login.pl_2", 
		"Action={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t189.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=username", "Value={newUsername}", ENDITEM, 
		"Name=password", "Value={newPassword}", ENDITEM, 
		"Name=passwordConfirm", "Value={newPassword}", ENDITEM, 
		"Name=firstName", "Value={newUsername}", ENDITEM, 
		"Name=lastName", "Value={newPassword}", ENDITEM, 
		"Name=address1", "Value=portland", ENDITEM, 
		"Name=address2", "Value=portland", ENDITEM, 
		"Name=register.x", "Value=66", ENDITEM, 
		"Name=register.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("UC06_03_Filling_data", LR_AUTO);


	lr_start_transaction("UC06_04_Profile");

		/* profile */

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

	lr_think_time(48);

	web_url("button_next.gif", 
		"URL={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=menus", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/login.pl", 
		"Snapshot=t191.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("login.pl_3", 
		"URL={protacol}://{host}:{port}/cgi-bin/login.pl?intro=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t192.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("nav.pl_2", 
		"URL={protacol}://{host}:{port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={protacol}://{host}:{port}/cgi-bin/welcome.pl?page=menus", 
		"Snapshot=t193.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("UC06_04_Profile", LR_AUTO);

	lr_end_transaction("UC06_New_user_registration", LR_AUTO);



	return 0;
}