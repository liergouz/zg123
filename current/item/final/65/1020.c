
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1207; }

// ���������촦��
void create()
{
        set_name("Ƥ���");
        set_picid_1(6678);
        set_picid_2(6678);

        set_level(20);
        set_value(2000);
        set_max_lasting(8899);
        set("ap", 0);
        set("dp", 35);
        set("cp", 0);
        set("pp", 20);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "Ƥ���";
}
