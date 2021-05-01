package main

import (
	"fmt"
	"net/http"
	"time"
)

//Context 跨 API 边界和协程携带了：deadline、取消信号以及其他请求范围的值。
func hello2(w http.ResponseWriter, req *http.Request) {
	ctx := req.Context()
	fmt.Println("server: hello handler started")
	defer fmt.Println("server: hello handler over")
	select {
	case <-time.After(10 * time.Second):
		fmt.Fprint(w, "hello world!\n")
	case <-ctx.Done():
		err := ctx.Err()
		fmt.Println("server", err)
		internalError := http.StatusInternalServerError
		http.Error(w, err.Error(), internalError)
	}
}

func main() {
	http.HandleFunc("/hello", hello2)
	http.ListenAndServe(":8080", nil)
}
