
const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const port = 3000;

// Middleware to parse JSON
app.use(express.json());
// Use body-parser middleware
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// Define a simple route
app.get('/', (req, res) => {
    const requestData = req.body;
    console.log('Received data:', requestData);
    const queryParams = req.query;
    console.log('Received query parameters:', queryParams);
    res.send('Hello, this is your Express server!');
});

// Example of handling POST requests
app.post('/api/data', (req, res) => {
    const requestData = req.body;
    res.json({ message: 'Received POST request', data: requestData });
});

// Start the server
app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});
