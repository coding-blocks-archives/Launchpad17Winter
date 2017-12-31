import soundcloud

# create a client object with your app credentials
client = soundcloud.Client(client_id='YOUR_CLIENT_ID')

# find all sounds of buskers licensed under 'creative commons share alike'
tracks = client.get('/tracks', q='buskers', license='cc-by-sa')