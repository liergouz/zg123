
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("���ǽ�ñ");
        set_picid_1(6638);
        set_picid_2(6638);

        set_level(80);
        set_value(21000);
        set_max_lasting(9099);
        set("dp", 69);
        set("pp", 51);

        setup();

        set_gender(2);
        set_head_code(56);
}

// ��������ȡ����
string get_desc()
{
        return "���ǽ�ñ";
}
