import Vue from 'vue'
import App from './App.vue'
import BootstrapVue from 'bootstrap-vue'

import firebase from 'firebase'

let firebaseConfig = {
  apiKey: "AIzaSyD5lEVKITzfAzKcK1wK_FY48uvRv-DDlIw",
  authDomain: "onsight-88888.firebaseapp.com",
  databaseURL: "https://onsight-88888.firebaseio.com",
  projectId: "onsight-88888",
  storageBucket: "onsight-88888.appspot.com",
  messagingSenderId: "314172702462",
    appId: "1:314172702462:web:8f9495c28a36557e5fefaf"
};

firebase.initializeApp(firebaseConfig)

Vue.use(BootstrapVue)
Vue.config.productionTip = false

export var database = firebase.database();
new Vue({
  render: h => h(App),
}).$mount('#app')


// import Vue from 'vue'
// import { firestorePlugin } from 'vuefire'
// import App from './App.vue'


// import firebase from 'firebase'
// import ApexCharts from 'apexcharts'
// import VueApexCharts from 'vue-apexcharts'
// import { ToggleButton } from 'vue-js-toggle-button'
// import BootstrapVue from 'bootstrap-vue';
// import 'bootstrap/dist/css/bootstrap.css'
// import 'bootstrap-vue/dist/bootstrap-vue.css'

// Vue.component('ToggleButton', ToggleButton)
// Vue.component('apexchart', VueApexCharts);
// Vue.config.productionTip = false
// Vue.use(BootstrapVue)
// Vue.use(firestorePlugin)
// let firebaseConfig = {
//   apiKey: "AIzaSyAr4XfjXnQ0MDKF8ItJF5g0_sfOJym5QdE",
//   authDomain: "guardian-8888.firebaseapp.com",
//   databaseURL: "https://guardian-8888.firebaseio.com",
//   projectId: "guardian-8888",
//   storageBucket: "",
//   messagingSenderId: "479861968929",
//   appId: "1:479861968929:web:e7f9b6edbc21d8f1941360"
// };

// firebase.initializeApp(firebaseConfig);

// export var database = firebase.database();
// new Vue({
//   render: h => h(App)
// }).$mount('#app')
