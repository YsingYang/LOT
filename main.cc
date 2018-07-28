    #include <ev.h>
    // a single header file is required
    //需要包含ev.h头文件
    #include <ev.h>

    #include <stdio.h> // for puts

    // every watcher type has its own typedef'd struct
    // with the name ev_TYPE
    //每一个观察者（watcher，以下还是用watcher吧，这种名称用中文很别扭）都有一个自己的结构体，结构体名称形如ev_TYPE

    ev_io stdin_watcher;
    ev_timer timeout_watcher;

    // all watcher callbacks have a similar signature
    // this callback is called when data is readable on stdin
    //所有的watcher回调函数也都有同样的函数签名
    //当stdin可读的时候，执行回调函数
    void
    stdin_cb (EV_P_ ev_io *w, int revents)
    {
        puts ("stdin ready");
        // for one-shot events, one must manually stop the watcher
        // with its corresponding stop function.
        // 对于只发生一次的事件来说，我们必须使用watcher的相应停止函数来手动停止这个watcher
        //译者注：它的意思是对于只需要触发一次的事件，我们必须使用不同类型相应的函数来停止这个watcher在loop中继续被监视
       //PS: 对于IO事件就是ev_io_stop,对于time事件  就是ev_time_stop
        ev_io_stop (EV_A_ w);

        // this causes all nested ev_run's to stop iterating
        //停止loop的运行，释放全部的watcher
        ev_break (EV_A_ EVBREAK_ALL);
    }

    // another callback, this time for a time-out
    //另外一个回调函数，是时间过期调用的
    void
    timeout_cb (EV_P_ ev_timer *w, int revents)
    {
        puts ("timeout");
        // this causes the innermost ev_run to stop iterating
        //停止当前loop循环
        ev_break (EV_A_ EVBREAK_ONE);
    }

    int
    main (void)
    {
        // use the default event loop unless you have special needs
        //除非你有特别的需求,一般使用默认的event loop即可
        struct ev_loop *loop = EV_DEFAULT;

        // initialise an io watcher, then start it
        // this one will watch for stdin to become readable
        //初始化一个io watcher，将事件和loop关联
        //这个watcher监视stdin是否可读
        ev_io_init (&stdin_watcher, stdin_cb, /*STDIN_FILENO*/ 0, EV_READ);
        ev_io_start (loop, &stdin_watcher);

        // initialise a timer watcher, then start it
        // simple non-repeating 5.5 second timeout
        //初始化一个超时watcher，并将事件和loop关联
        //简单的非重复5.5s超时
        ev_timer_init (&timeout_watcher, timeout_cb, 5.5, 0.);
        ev_timer_start (loop, &timeout_watcher);

        // now wait for events to arrive
        //开始监听事件
        ev_run (loop, 0);

        // break was called, so exit
        return 0;
    }
