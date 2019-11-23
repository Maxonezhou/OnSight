<template>
  <div id="app">
    <b-jumbotron header="OnSight" style="width: 50%; margin: 0 auto; opacity: 0.9;" lead="Novel Approach for First Responders">
       <b-img class="logo" rounded alt="Rounded image" thumbnail src="https://i.ibb.co/7jJV8C2/logo.png"></b-img>
        <!-- <img style="opacity: 1" src="https://image.flaticon.com/icons/svg/206/206877.svg" height="200px"></img> -->
        <!-- <p>For more information visit website</p>
        <b-button variant="primary" href="#">More Info</b-button> -->
      </b-jumbotron>
    <!-- <img alt="Vue logo" src="./assets/logo.png"> -->
    <b-table striped hover :items="items"></b-table>
    <b-input-group prepend="Send Report" class="mt-5">
       <b-form-input></b-form-input>
      <b-input-group-append>
        <b-button variant="primary">Enter</b-button>
      </b-input-group-append>
    </b-input-group>
  </div>
</template>

<script>
import firebase from 'firebase'
import {database} from './main'

export default {
  name: 'app',
  components: {

  },
  data() {
    return {
      items: [
          { age: 40, first_name: 'Dickerson', last_name: 'Macdonald' },
          { age: 21, first_name: 'Larsen', last_name: 'Shaw' },
          { age: 89, first_name: 'Geneva', last_name: 'Wilson' },
          { age: 38, first_name: 'Jami', last_name: 'Carney' }
      ]
    }
  }, 
  created() {
    const infoRef = database.ref('').child('')
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

.logo {
  height:350px;
}
</style>
