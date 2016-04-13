#!/bin/bash
openssl rand -out sample.txt -base64 $(( 2**24 * 3/4 ))
