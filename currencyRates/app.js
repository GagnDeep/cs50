d3.queue()
    .defer(d3.csv,'./data.csv')
    .await((err,data)=>{
        if(err) throw err;
        let newObj = {};
        data.forEach(obj => {
 for (val in obj) {
                if (parseInt(val)) {
                    if (!newObj[val]) newObj[val] = [];
                    let yearArr = newObj[val]
                    let rate = obj[val] ? obj[val] : null;
                    if (!rate) continue;
                    if (!yearArr.find(d=>d.countryName == obj['Country Name']))
                        yearArr.push({
                            countryName: obj['Country Name'],
                            countryCode: obj['Country Code'],
                            exhangeRate: rate
                        })
                }
            }
        })
debugger;
    })

// function formatter(data){
//     debugger
// }