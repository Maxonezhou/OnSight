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
// import firebase from 'firebase'
import {database} from './main'

export default {
  name: 'app',
  components: {

  },
  data() {
    return {
        temperatureData: []
    }
  }, 
  created() {
    const listRef = database.ref('list')

      listRef.limitToLast(1).on('value', querySnapshot => {
      let data = querySnapshot.val();
      let value = Object.values(data);
      // eslint-disable-next-line no-console
      console.log(data);
      // eslint-disable-next-line no-console
      console.log(value);

     
      this.temperatureData.push({"test":"success!"})
      if (this.temperatureData.length > 8) {
        this.temperatureData = this.temperatureData.slice(this.temperatureData.length - 8, this.temperatureData.length)
      }
      
      this.$refs.temperatureChart.updateSeries([{
        data: this.temperatureData
      }])
    });
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
