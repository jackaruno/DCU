from django.shortcuts import render
from django.http import HttpResponse
# Create your views here.

def index(request):
    return render(request, 'index.html')

def contacts(request):
    contact = "John"
    return render(request, 'contacts.html', {"contact":contact})