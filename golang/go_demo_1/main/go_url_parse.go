package main

import (
	"fmt"
	"net"
	url2 "net/url"
)

func main() {
	url := "postgres://user:pass@host.com:5432/path?k=v#f"
	parse, err := url2.Parse(url)
	if err != nil {
		return
	}
	fmt.Println(parse.Scheme)
	fmt.Println(parse.User)
	fmt.Println(parse.User.Username())
	pass, _ := parse.User.Password()
	fmt.Println(pass)

	fmt.Println(parse.Host)
	host, port, err := net.SplitHostPort(parse.Host)
	if err != nil {
		return
	}
	fmt.Println(host)
	fmt.Println(port)
	fmt.Println(parse.Path)
	fmt.Println(parse.Fragment)
	fmt.Println(parse.RawQuery)

	m, _ := url2.ParseQuery(parse.RawQuery)
	fmt.Println(m)
	fmt.Println(m["k"])

}
