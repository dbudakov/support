# Vagrantfile

```sh
# -*- mode: ruby -*-
# vi: set ft=ruby:
home = ENV['HOME']

MACHINES = {
	:'test-vm' => {
		:box_name => "ubuntu/bionic64",
		:ip_addr => '192.168.100.201',
	}
}

Vagrant.configure("2") do |config|

	MACHINES.each do |boxname, boxconfig|

		config.vm.define boxname do |box|

			# ansible
			# box.vm.provision "ansible", playbook = "playbooks/pgsql.yml", become = "true"
			
			# ansible column
			# box.vm.provision "ansible" do |ansible|
			# 	#ansible.verbose = "vvv"
			# 	ansible.playbook = "playbooks/pgsql.yml"
			# 	ansible.become = "true"
			# end
			
			# shell string
			# box.vm.provision "shell", inline: "echo hello", run: "always"
			
			# shell column
			# box.vm.provision "shell"  do |s|
			#     s.inline = "echo hello"
			# end
			
			# shell tag and EOF
			# box.vm.provision "bootstrap", type: "shell", run: "never" do |s|
			
			# box.vm.provision "shell", inline:<<SHELL
			# SHELL
		end
	end
end
```
