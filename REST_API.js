#REST for cloud/mobile/web integration (modern, supported, easy to extend).

const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const PORT = 5000;

app.use(bodyParser.json());

app.post('/api/pillbox/data', (req, res) => {
  const { timestamp, sensorValue, status } = req.body;

  console.log(`Received PillBox Data:
  Time: ${timestamp}
  Value: ${sensorValue}
  Status: ${status}`);

  res.status(200).json({ message: 'Data received successfully' });
});

app.listen(PORT, () => {
  console.log(`REST API server running at http://localhost:${PORT}`);
});
