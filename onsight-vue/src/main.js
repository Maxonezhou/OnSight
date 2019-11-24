import Vue from 'vue'
import App from './App.vue'
import BootstrapVue from 'bootstrap-vue'

import firebase from 'firebase'

let firebaseConfig = {
  // API key will be deactivated immediately after hackathon so we're exposing it only for the duration of the hackathon.
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