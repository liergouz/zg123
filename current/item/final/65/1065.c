
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 2166; }

// ���������촦��
void create()
{
        set_name("�׺׿�");
        set_picid_1(6642);
        set_picid_2(6642);

        set_level(65);
        set_value(9000);
        set_max_lasting(22899);
        set("ap", 0);
        set("dp", 125);
        set("cp", 0);
        set("pp", 44);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�׺׿�";
}
