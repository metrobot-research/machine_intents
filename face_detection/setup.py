from setuptools import setup

package_name = 'face_detection'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Jaiveer Singh',
    maintainer_email='j.singh@berkeley.edu',
    description='Facial detection wrapper for the MetroBot Intents system',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'face_detection_node = face_detection.face_detection'
        ],
    },
)
