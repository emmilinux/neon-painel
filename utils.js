.pragma library

function getTime() {

    var d = new Date();

    var h,m,s;

    h = d.getHours()
    m = d.getMinutes()

    if (h < 10) h = '0' + h
    if (m < 10) m = '0' + m

    return h + ':' + m;
}
