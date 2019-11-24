import Vue from 'vue'
import { firestorePlugin } from 'vuefire'
import App from './App.vue'

import firebase from 'firebase'
import BootstrapVue from 'bootstrap-vue';
import 'bootstrap/dist/css/bootstrap.css'
import 'bootstrap-vue/dist/bootstrap-vue.css'

Vue.config.productionTip = false
Vue.use(BootstrapVue)
Vue.use(firestorePlugin)
let firebaseConfig = {
  apiKey: "",
  authDomain: "guardian-8888.firebaseapp.com",
  databaseURL: "https://onsight-88888.firebaseio.com/",
  projectId: "onsight-88888",
  storageBucket: "",
  appId: "1:314172702462:web:8f9495c28a36557e5fefaf"
};

firebase.initializeApp(firebaseConfig);

export var database = firebase.database();
new Vue({
  render: h => h(App)
}).$mount('#app')