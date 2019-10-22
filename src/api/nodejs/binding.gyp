{
	"targets": [
		{
			"target_name": "sqlrelay",
			"sources": ["sqlrelay.cpp"],
			"include_dirs": [
				""
			],
			"cflags": [
				"-std=c++11 -I/root/sqlrelay-1.6.0/src/api/c++ "
			],
			"xcode_settings": {
				"cflags": [
					"-std=c++11 -I/root/sqlrelay-1.6.0/src/api/c++ "
				],
			},
			"libraries" : [
				"-L/root/sqlrelay-1.6.0/src/api/c++/.libs -lsqlrclient -L/usr/lib64 -lrudiments -lpthread -ledit -ltermcap -lssl -lcrypto -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err -lkrb5 -lk5crypto -lcom_err -lpcre -lcurl -lcrypt -ldl"
			]
		}
	]
}
