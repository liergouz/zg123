
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 2071; }

// ���������촦��
void create()
{
        set_name("�����װ");
        set_picid_1(6038);
        set_picid_2(6038);

        set_level(100);
        set_value(7000);
        set_max_lasting(17899);
        set("ap", 0);
        set("dp", 230);
        set("cp", 0);
        set("pp", 165);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�����װ";
}
