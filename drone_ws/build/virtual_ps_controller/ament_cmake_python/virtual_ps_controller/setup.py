from setuptools import find_packages
from setuptools import setup

setup(
    name='virtual_ps_controller',
    version='0.0.0',
    packages=find_packages(
        include=('virtual_ps_controller', 'virtual_ps_controller.*')),
)
