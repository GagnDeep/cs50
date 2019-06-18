var express = require('express');
var router = express.Router();
var db = require('../models/model.js');
var helpers = require('../helpers/index.js');

router.route('/')
    .get(helpers.getTodos)
    .post(helpers.createTodo)

router.route('/:id')
    .get(helpers.getOne)
    .put(helpers.update)
    .delete(helpers.delete)

module.exports = router;