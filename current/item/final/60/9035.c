
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 1233; }

// ���������촦��
void create()
{
        set_name("�߼��鲼��");
        set_picid_1(6038);
        set_picid_2(6038);

        set_level(35);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 60);
        set("cp", 0);
        set("pp", 105);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�߼��鲼��";
}
