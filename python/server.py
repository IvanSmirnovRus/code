from bottle import route, run


@route('/beta')
def get_beta():
	return 'Hello, World!'

run(host='localhost', port=10000, debug=True)

