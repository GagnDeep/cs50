var mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/todos');
mongoose.Promise = Promise;
module.exports.Todo = require('./todo.js')