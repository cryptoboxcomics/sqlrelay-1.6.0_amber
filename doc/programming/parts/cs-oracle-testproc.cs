cur.prepareQuery("begin exampleproc(:in1,:in2,:in3); end;");
cur.inputBind("in1", 1);
cur.inputBind("in2", 1.1, 2, 1);
cur.inputBind("in3", "hello");
cur.executeQuery();
