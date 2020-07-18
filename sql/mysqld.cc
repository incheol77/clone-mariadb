

int mysqld_server_started = 0, mysqld_server_initialized = 0;


void mysql_service(void *p)
{
	if (my_thread_init())
		abort();
}

int mysqld_main(int argc, char **argv)
{
	my_progname = argv[0];
	mysqld_server_started = 0;
	mysqld_server_initialized = 0;

	// init my_sys library & pthreads
	if (my_init())
	{
		fprintf(stderr, "my_init() failed.");
		return 1;
	}

	/* Start as standalone server */
	Service.my_argc = argc;
	Service.my_argv = argv;
	mysql_service(NULL);

	return 0;
}
