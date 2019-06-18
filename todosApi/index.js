var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var todoRoutes = require('./routes/routes.js')

app.use(bodyParser.urlencoded({extended : true}));
app.use(express.static(__dirname + '/views'));
app.use(express.static(__dirname + '/public'));

app.get('/',function(req,res){
    res.sendFile('index.html')
})

app.use('/api/todos',todoRoutes);
app.listen(process.env.PORT,process.env.IP,function(err){
    if(err){
       console.log(err);
    }else{
        console.log('Server is Listening');
    }
})
