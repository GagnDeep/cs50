d3.queue()
    .defer(d3.json, '//unpkg.com/world-atlas@1.1.4/world/50m.json')
    .defer(d3.json, './reporterAreas.json')
    .defer(d3.csv,'./data/data.csv', formatter2)
    .await((err, mapData, isoCode,emissionData)=>{
        if(err) throw err;
        formatter(mapData, isoCode)
        let yearData = formatAllData(emissionData);

        let geojson = topojson.feature(mapData, mapData.objects.countries).features;
        debugger;

        let maxMin = d3.extent(Object.keys(yearData))
        let height = 600, width = 960;
        let svg = d3.select('#map')
                    .attr('height', height)
                    .attr('width', width)
        d3.select('input')
            .attr('min', maxMin[0])
            .attr('max', maxMin[1])
            .attr('value', maxMin[0])
            .on('input', ()=>makeMap(+d3.event.target.value))
        makeMap(maxMin[0])
        function makeMap(year){
            let emissions = yearData[year];
            emissions.forEach(row=>{
                let countries = geojson.filter(d=>{let bool = d.id== row.country;return bool})

                countries.forEach(country=>country.properties = row)
            })
                // debugger
            let projection = d3.geoMercator()
                                .scale(125)
                                .translate([width/2, height/1.4]);

            let path = d3.geoPath()
                            .projection(projection);

            let update = svg
                            .selectAll('.country')
                            .data(geojson)
                update
                    .exit()
                    .remove();
              update
                    .enter()
                    .append('path')
                    .classed('country', true)
                    // .merge(update)
                    .attr('d', path)
                    .attr('fill', '#fff')
                let colorScale = d3.scaleLinear()
                                    .domain([0,d3.max(emissions, d=>d.co2)])
                                    .range(["yellow","red"])
                    setColor()
            function setColor(){

                d3.selectAll('.country')
                    .transition()
                    .duration(7500)
                    .ease(d3.easeBackIn)
                    .attr('fill',d=>{
                        if(d.properties.co2){
                            return colorScale(d.properties.co2)
                        }else return '#ccc'
                    })
            }
            // debugger
        }
        // debugger;
    })

function formatter(data, data2){
    data.objects.countries.geometries.forEach(obj=>{
        let id = data2.results.find(d=>d.id == +obj.id)
        if(id) obj.id = id.text.split(' ')[0].replace(',','').toLowerCase();
        else obj.id = null;
    })
}

function formatter2(row){
    let obj={
        country:row["Country Name"],
        indicator:row["Indicator Name"]
    }
    for(let key in row){
        if(parseInt(key)) obj[key] = +row[key]||null;
    }
    return obj;
}
function formatAllData(data){
    let yearObj = {};
    let indicator = data[0].indicator.split(' ')[0].toLowerCase();
    data.forEach(obj=>{
        let country = obj.country;
        for(var year in obj){
            if(parseInt(year)){
                if(!yearObj[year]) yearObj[year] = []
                let yearArr = yearObj[year];
                let regionObj = yearArr.find(el=>el.country == country)
                if(regionObj) regionObj[indicator] = obj[year]
                else{
                    yearArr.push({
                        country : country.split(' ')[0].replace(',','').toLowerCase(),
                        [indicator] : obj[year]
                    })
                }
            }
        }
    })
    for(let year in yearObj){
        yearObj[year] = yearObj[year].filter(checkYear)
        if(yearObj.length == 0) delete yearObj[year]
    }
    return yearObj;
}
function checkYear(d) {
      for (var key in d) {
        if (d[key] === null) return false;
      }
      return true;
    }