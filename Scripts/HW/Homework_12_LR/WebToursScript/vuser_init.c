vuser_init()
{
	web_cache_cleanup();

	web_cleanup_auto_headers();

	web_cleanup_cookies();

	return 0;
}
