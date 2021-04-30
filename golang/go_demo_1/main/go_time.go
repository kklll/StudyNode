package main

import (
	"fmt"
	"time"
)

func main() {
	p := fmt.Println
	now := time.Now()
	local, _ := time.LoadLocation("Asia/Shanghai")
	withLocal := now.In(local)
	fmt.Println(withLocal)
	p(now)
	then := time.Date(2021, 5, 1, 13, 22, 00, 0, time.UTC)
	p(then)
	p(then.Year())
	p(then.Month())
	p(then.Day())
	p(then.Hour())
	p(then.Minute())
	p(then.Second())
	p(then.Nanosecond())
	p(then.Location())
	p(then.Weekday())
	p(then.Before(now))
	p(then.After(now))
	p(then.Equal(now))
	diff := now.Sub(then)
	p(diff.Hours())
	p(diff.Minutes())
	p(diff.Seconds())
	p(diff.Nanoseconds())
	p(then.Add(diff))
	p(then.Add(diff))
}
