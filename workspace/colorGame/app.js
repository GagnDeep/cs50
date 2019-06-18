var express = require("express");
var app = express();
var mongoose = require("mongoose");
var passport = require("passport");
var localStrategy = require("passport-local");
var bodyParser = require("body-parser");
var passportLocalMongoose = require("passport-local-mongoose");
var expressSession = require("express-session");
//Models
var profileSchema = mongoose.Schema({
    image:String,
    description:String,
    age:String,
    x:Boolean
})
var Profile = mongoose.model("profile",profileSchema);

var userSchema = mongoose.Schema({
    username:String,
    password:String,
    profile:[profileSchema]
});
userSchema.plugin(passportLocalMongoose);

var User = mongoose.model("User",userSchema);

mongoose.connect("mongodb://localhost/colorgame");
app.set("view engine","ejs");
app.set('views', __dirname + '/views');
app.use(express.static(__dirname + "/public"));
app.use(expressSession({
    secret:"gagandeep singh is a very good person",
    resave:false,
    saveUninitialized:false
}));
app.use(passport.initialize());
  app.use(passport.session());
  passport.serializeUser(User.serializeUser());
  passport.deserializeUser(User.deserializeUser());

    passport.use(new localStrategy(User.authenticate()));

app.use(bodyParser.urlencoded({extended:true}));

  passport.use(new localStrategy(User.authenticate()));
// app.use("views",__dirname+"/views");
app.use(function(req,res,next){
    res.locals.currentUser = req.user;
    next();
})

app.get("/",function(req,res){
    res.render("index");
});


app.get("/login",function(req,res){
    res.render("login");
});
app.post("/profile",function(req,res){
    var obj = {
        image:req.body.image,
        description:req.body.description,
        age:req.body.image,
        x:true
    }
 User.findOne({username:req.user},function(err,user){
     if(err){
         console.log(err);
     }else{
         user.profile.push(obj);
         user.save();
     }
 })
})

app.post("/register",function(req,res){
    var newUser = new User({username:req.body.username});
    User.register(newUser,req.body.password,function(){
        passport.authenticate("local")(req,res,function(err,user){
            if(err){
                console.log(err);
            }
            console.log(user);
            res.redirect("/");
        })
    })
})
app.post("/login",passport.authenticate("local",{
    successRedirect:"/",
    failureRedirect:"/error"
}))
app.get("/register",function(req,res){
    res.render("signup");
});
app.get("/profile",isLoggedIn,function(req,res){
    res.render("profile");
})
app.get("/logout",function(req,res){
    req.logout();
    res.redirect("/");
});
app.get("/profileUpdate",function(req,res){
    res.render("profileform");
})

function isLoggedIn(req,res,next){
    if(req.isAuthenticated()){
        return next();
    }else{
        res.redirect("/login");
    }
}
app.listen(process.env.PORT,process.env.IP,function(){
    console.log("server has started");
});