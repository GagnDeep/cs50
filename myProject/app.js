/*global d3*/
let yearData,dataType, countries,countryData, id, recentlyClicked;
let continents = ["Asia", "Europe", "Africa", "Americas", "Oceania"];


d3.queue()
    .defer(d3.json, '//unpkg.com/world-atlas@1.1.4/world/50m.json')
    .defer(d3.csv, './data/all_data.csv', formatter)
    .await(init);


function init(error, mapData, data){

        if(error) throw error;
        // debugger;

            yearData        = formatAllData(data);
            dataType        = 'emissionsPerCapita';
            countryData     = countryFormatter(data);


        let height          = 600,
            width           = 960,
            minMax          = d3.extent(Object.keys(yearData)),

            geoData         = topojson.feature(mapData, mapData.objects.countries).features;
            projection      = d3.geoMercator()
                                    .scale(125)
                                    .translate([width/2, height/1.4]),

            path            = d3.geoPath()
                                    .projection(projection),


            barSvg          = d3.select('#histogram');

            barSvg
                .append('g')
                .classed('x-axis', true);

            barSvg
                .append('g')
                .classed('y-axis', true)




        countries = d3.select('#map')
                           .attr('height', height)
                           .attr('width', width)
                             .selectAll('.country')
                               .data(geoData)
                               .enter()
                               .append('path')
                               .attr('d', path)
                               .classed('country', true)
                               .on('click', d=>{
                                   histogram(d)
                                   highlight(d3.event.target)
                               });


        //calling functions
             initiators(300, 300)
             histogram({id:-1})
             makeMap(minMax[0]);
             eventListeners(minMax);
}


function initiators(width, height){
        d3.select('#pie')
            .attr('height',height)
            .attr('width', width)
            .append('g')
            .classed('chart', true)
            .attr('transform', `translate(${width/2}, ${width/2})`);

        d3.select('body')
            .append('div')
            .classed('tooltip', true);
}

function highlight(element){
    if(!recentlyClicked){
        recentlyClicked = d3.select(element)
                              .classed('clicked',true)
        }else{
            let e = d3.select(element)
            if(e.classed('clicked')){
                e.classed('clicked', false);
                histogram({id:-1})
            }else{
                recentlyClicked.classed('clicked', false);
                recentlyClicked = e.classed('clicked', true)
            }
     }
}