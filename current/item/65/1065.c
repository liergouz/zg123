
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("���ƹ�");
        set_picid_1(6558);
        set_picid_2(6558);

        set_level(65);
        set_value(19000);
        set_max_lasting(11499);
        set("dp", 77);
        set("pp", 42);

        setup();

        set_gender(1);
        set_head_code(45);
}

// ��������ȡ����
string get_desc()
{
        return "���ƹ�";
}
