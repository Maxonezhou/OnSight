<template>
  <div id="app">
    <h1>OnSight Dashboard</h1>
    <div style="h-50">
      <img id="logo" src="https://image.flaticon.com/icons/svg/763/763421.svg">
    </div>
    <h3 id="description">Reimagining Emergency Response</h3>
  
    <table class="table">
      <thead id="tableHead">
        <th>Situation</th>
        <th>Emergency Level</th>
        <th>Location</th>
        <th>Details</th>
        <th>Location</th>
        <th>Contact</th>
      </thead>
      <tr v-for="info in infoList.reverse()" :key="info.emergency_level">
        <td>{{info.situation}}</td>
        <td>{{info.emergency_level}}</td>
        <td>{{info.location}}</td>
        <td>{{info.details}}</td>
        <td> 
          <iframe
            width="600"
            height="450"
            frameborder="0" style="border:0"
            v-bind:src="getUrl(info.location)" allowfullscreen>
          </iframe>
        </td>
        <td>
          <div id=contactText> 
            <strong>Contact Closest First Responder    </strong>
            <b-button block variant="danger">CONTACT</b-button>
          </div>
        </td>
      </tr>
    </table>
  </div>
</template>

<script>
// import firebase from 'firebase'
import {database} from './main'

export default {
  name: 'app',
  components: {

  },
  data() {
    return {
      infoData: '',
      infoList: []
    }
  }, 
  created() {
    const infoRef = database.ref('list')

    infoRef.limitToLast(1).on('value', data => {
      let fireBaseVal = data.val();
      let value = Object.values(fireBaseVal);

      console.log(value[0]);

      
      value.forEach(val => {
        if(value[0].situation != undefined) {
          this.infoList.push(val);
        }
      })
  
      
    })
    

  },
  methods: {
    getUrl(location) {  
      // API key will be deactivated immediately after so no need for environment variables to keep it simple
      return "https://www.google.com/maps/embed/v1/place?key=AIzaSyCwcjGNNNbFM71APT-x_37YYqexjDTrBTM&q="+ location
    }

  }
}
</script>

<style>

#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}

#logo {
  height: 150px;
}

#contactText {
  font-size: 1pc;
  align-content: center
}

#description {
  padding: 20px 20px 20px 20px
}
.logo {
  height:200px;
}
</style>
