.pragma library

function getTime() {

    var d = new Date();

    var h, m, s, date;

    h = d.getHours()
    m = d.getMinutes()
    date = d.getDate() + '/' + d.getMonth() + '/' + d.getFullYear()

    if (h < 10) h = '0' + h
    if (m < 10) m = '0' + m

    return h + ':' + m + '|' + d.toString().split(' ')[0] + ' - ' + date;
}
