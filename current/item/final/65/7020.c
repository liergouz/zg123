
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 7; }

// ��������Ʒ���
int get_fin_type() { return 1210; }

// ���������촦��
void create()
{
        set_name("�ż׹�");
        set_picid_1(6678);
        set_picid_2(6678);

        set_level(20);
        set_value(2000);
        set_max_lasting(8899);
        set("ap", 0);
        set("dp", 26);
        set("cp", 0);
        set("pp", 35);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�ż׹�";
}
